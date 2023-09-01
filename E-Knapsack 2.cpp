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

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 100000;

ll inv(long long i){
    return i <= 1 ? i : MOD - (MOD / i) * inv(MOD % i) % MOD;
}

void solve(){
    ll n, w;
    std::cin >> n >> w;
    
    std::vector<std::pair<ll, ll>> a(n);
    ll mx = 0;
    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
        mx = std::max(mx, a[i].second);
    }

    mx *= n;
    // dp[i] - min weight for value to be >= i
    std::vector<ll> dp(mx + 1, 1e12);
    dp[0] = 0;

    for (int i=0;i<n;i++){
        for (auto j=mx;j>=1;j--){
            dp[j] = std::min(dp[j], a[i].first + dp[std::max(0LL, j - a[i].second)]);
        }
    }

    ll ans = 0;
    for (int i=1;i<=mx;i++){
        if (dp[i] <= w) ans = i;
    }

    std::cout << ans << '\n';
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
