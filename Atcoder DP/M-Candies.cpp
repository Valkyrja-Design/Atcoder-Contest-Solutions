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

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    // #ways to distribute k candies
    std::vector<ll> dp(k + 1);
    std::vector<ll> prefix(k + 1, 1);
    dp[0] = 1;
    
    for (int i=0;i<n;i++){
        for (int j=k;j>=1;j--){
            int l = std::max(0, j - a[i]);
            // dp[j] = sum_k (dp[j - k]) where 0 <= k <= a[i]
            dp[j] = (MOD + prefix[j] - (!l ? 0 : prefix[l - 1])) % MOD;
        }
        // prefix sums over dp
        for (int j=1;j<=k;j++){
            prefix[j] = (prefix[j - 1] + dp[j]) % MOD;
        }
    }

    std::cout << dp[k] << '\n';
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
