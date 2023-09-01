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

void update(int v, int tl, int tr, int idx, ll val){
    if (tl == tr){
        t[v] = std::max(t[v], val);
    } else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm)
            update(2 * v, tl, tm, idx, val);
        else 
            update(2 * v + 1, tm + 1, tr, idx, val);
        t[v] = std::max(t[2 * v], t[2 * v + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[v];
    
    int tm = (tl + tr) >> 1;
    return std::max(query(2 * v, tl, tm, l, std::min(tm, r))
            , query(2 * v + 1, tm + 1, tr, std::max(tm + 1, l), r));
}

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i=0;i<n;i++){
        std::cin >> h[i];
        h[i]--;
    }

    std::vector<ll> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    } 

    // dp[i] - maximum beauty on the prefix [0 : i] 
    // when i-th is not plucked
    std::vector<ll> dp(n);
    t.resize(4 * n, 0);
    dp[0] = a[0];
    update(1, 0, n - 1, h[0], a[0]);

    for (int i=1;i<n;i++){
        dp[i] = a[i];
        // max value of prev dp's with height less than current height
        if (h[i])
            dp[i] = std::max(dp[i], a[i] + query(1, 0, n - 1, 0, h[i] - 1));
        update(1, 0, n - 1, h[i], dp[i]);
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
