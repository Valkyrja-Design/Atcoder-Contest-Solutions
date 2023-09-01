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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i=0;i<n;i++){
        std::cin >> grid[i];
    }

    std::vector<std::vector<ll>> dp(n, std::vector<ll>(m, 0));

    dp[0][0] = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == '#') continue;
            if (i)
                dp[i][j] += dp[i - 1][j];
            if (j)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    std::cout << dp[n - 1][m - 1] << '\n';
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
