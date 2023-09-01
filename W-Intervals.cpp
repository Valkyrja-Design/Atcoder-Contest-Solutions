#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <iomanip>

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 100000;

ll inv(long long i){
    return i <= 1 ? i : MOD - (MOD / i) * inv(MOD % i) % MOD;
}

std::vector<ll> t;
std::vector<ll> lazy;

void push(int v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    t[2*v] += lazy[v];
    t[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, ll val){
    if (l > r)
        return;
    if (tl == l && tr == r){
        t[v] += val;
        lazy[v] += val;
    } else {
        push(v);
        int tm = (tl + tr) >> 1;
        update(2*v, tl, tm, l, std::min(tm, r), val);
        update(2*v+1, tm+1, tr, std::max(tm+1, l), r, val);
        t[v] = std::max(t[2*v], t[2*v+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r)
        return -1e17;
    if (tl == l && tr == r)
        return t[v];
    
    push(v);
    int tm = (tl + tr) >> 1;
    return std::max(query(2*v, tl, tm, l, std::min(tm, r))
            , query(2*v+1, tm+1, tr, std::max(tm+1, l), r));
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    
    struct Interval{
        int l;
        int r;
        ll score;
    };

    enum class type{LEFT, RIGHT};

    struct Event{
        int x;
        int y;
        type t;    
        ll score;
    };

    std::vector<Interval> a(m);
    // left and right of an interval
    std::vector<Event> events;
    for (int i=0;i<m;i++){
        std::cin >> a[i].l >> a[i].r >> a[i].score;
        a[i].l--, a[i].r--;
        events.push_back({a[i].l - 1, a[i].r, type::LEFT, a[i].score});
        events.push_back({a[i].r, a[i].l, type::RIGHT, a[i].score});
    }

    std::sort(events.begin(), events.end(), [](const Event& left, const Event& right){
        return left.x > right.x;
    });

    t.resize(4 * (n + 1));
    lazy.resize(4 * (n + 1));

    // dp[i] - max score if i-th char is 1
    // to determine this, we set the position of 
    // next one = j and assign dp[i] = curr_score + max_j (dp[j]) j > i
    std::vector<ll> dp(n + 1);
    dp[n] = 0;
    int j = 0;
    ll curr_score = 0;
    for (int i=n-1;i>=0;i--){
        // calculates the curr_score for the intervals
        // intersecting this index
        while (j < 2*m && events[j].x >= i){
            if (events[j].t == type::RIGHT){
                curr_score += events[j].score;
                // since we'll set this index as 1 
                // the remaining indices which this interval covers
                // must not count the score of this 
                // interval so we subtract the score from their dp's
                update(1, 0, n, events[j].y, events[j].x, -events[j].score);
            } else {
                curr_score -= events[j].score;
                // add score in case the interval didn't intersect the 
                // current index
                update(1, 0, n, events[j].x + 1, events[j].y, events[j].score);
            }
            j++;
        }
        auto q = query(1, 0, n, i + 1, n);
        dp[i] = curr_score + q;

        // add dp[i] in seg tree
        update(1, 0, n, i, i, dp[i]);
    }

    std::cout << (*std::max_element(dp.begin(), dp.end())) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--){
        solve();
    }
}

/*

*/
