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
    std::string a, b;
    std::cin >> a >> b;

    int n = a.length();
    int m = b.length();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (!i || !j){
                dp[i][j] = 0;
                continue;
            }
            if (i)
                dp[i][j] = dp[i - 1][j];
            if (j)
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            if (i && j)
                dp[i][j] = std::max(dp[i][j], (a[i - 1] == b[j - 1]) + dp[i - 1][j - 1]);
        }
    }

    std::string ans;
    int i = n;
    int j = m;
    while (i && j){
        if (a[i - 1] == b[j - 1]){
            ans += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]){
            i--;
        } else {
            j--;
        }
    }

    std::reverse(ans.begin(), ans.end());
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
