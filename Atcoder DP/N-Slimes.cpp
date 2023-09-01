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
    int n;
    std::cin >> n;

    std::vector<ll> a(n);
    std::vector<ll> prefix(n + 1);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    // dp[i][j] - min cost for this subarray
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, -1));
    for (int i=0;i<n-1;i++){
        dp[i][i+1] = a[i] + a[i + 1];
        dp[i][i] = 0;
    }
    dp[n - 1][n - 1] = 0;

    for (int i=n-2;i>=0;i--){
        for (int j=i+2;j<n;j++){
            dp[i][j] = LLONG_MAX;
            // we iterate over the left and right subarrays 
            for (int k=i;k<j;k++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j + 1] - prefix[i]);
            }
        }
    }

    std::cout << dp[0][n - 1] << '\n';
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
