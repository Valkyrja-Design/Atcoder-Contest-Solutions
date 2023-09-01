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
    ll sum = 0;
    for (int i=0;i<n;i++){
        std::cin >> a[i];
        sum += a[i];
    }

    // max score of Taro on array [i, j] when turn is k
    std::vector<std::vector<std::vector<ll>>> dp(n, std::vector<std::vector<ll>>(n, std::vector<ll>(2, 0)));
    for (int i=0;i<n;i++){
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }

    for (int i=n-2;i>=0;i--){
        for (int j=i+1;j<n;j++){
            // Taro's turn
            dp[i][j][0] = std::max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            // Jiro's turn
            dp[i][j][1] = std::min(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }

    std::cout << 2 * dp[0][n - 1][0] - sum << '\n';
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
