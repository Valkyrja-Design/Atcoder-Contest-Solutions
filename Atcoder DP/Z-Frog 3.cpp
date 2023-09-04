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

// Li Chao Tree
// https://robert1003.github.io/2020/02/06/li-chao-segment-tree.html
// https://cp-algorithms.com/geometry/convex_hull_trick.html#li-chao-tree

// we'll store function at each segment 
// which gives the min value at the mid point of 
// the segment
struct Line{
    ll a;
    ll b;
    ll operator()(ll x) const {
        return a * x + b;
    }
};

const ll maxn = 1e6 + 4;
std::vector<Line> lines;

void add_line(Line line, ll v = 1, ll tl = 0, ll tr = maxn){
    auto tm = (tl + tr) >> 1;
    // we check where the intersection of the 
    // old and new function lies, we assume that 
    // the slope of old line < new line
    bool mid = lines[v](tm) < line(tm);    

    if (!mid){  // intersection lies in the right segment
        // swap for new line gives lesser value
        std::swap(lines[v], line);
    }    

    if (tr == tl + 1)
        return;

    if (mid){  // update in left segment
        add_line(line, 2*v, tl, tm);
    } else {
        add_line(line, 2*v+1, tm, tr);
    }
}

// get min value of ax + b considering all the lines
ll get_min(ll x, ll v = 1, ll tl = 0, ll tr = maxn){
    auto tm = (tl + tr) >> 1;

    if (tr == tl + 1)
        return lines[v](x);

    // if the point lies in the left segment
    if (x < tm)
        return std::min(lines[v](x), get_min(x, 2*v, tl, tm));

    return std::min(lines[v](x), get_min(x, 2*v+1, tm, tr));
}

void solve(){
    int n;
    std::cin >> n;
    ll c;
    std::cin >> c;
    std::vector<ll> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    lines.resize(4 * maxn, {0, (ll)(2*1e18)});
    std::vector<ll> dp(n, 0);

    add_line({-2 * a[n - 1], a[n - 1] * a[n - 1] + c});
    for (int i=n-2;i>=0;i--){
        dp[i] = a[i] * a[i] + get_min(a[i]);
        add_line({-2 * a[i], a[i] * a[i] + dp[i] + c});
    }
    std::cout << dp[0] << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

/*

*/