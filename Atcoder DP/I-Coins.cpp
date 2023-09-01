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
     
    std::vector<double> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    // dp[i][j] - prob that the number of heads is j for the first
    // i tosses
    std::vector<std::vector<double>> dp(n, std::vector<double>(n + 1, 0));
    dp[0][1] = a[0];
    dp[0][0] = 1 - a[0];

    for (int i=1;i<n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = dp[i - 1][j] * (1 - a[i]);
            if (j)
                dp[i][j] += a[i] * dp[i - 1][j - 1];
        }
    }

    double ans = 0;
    for (int i=(n + 1)/2;i<=n;i++){
        ans += dp[n - 1][i];
    }

    std::cout << std::setprecision(10) << ans << '\n';
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
