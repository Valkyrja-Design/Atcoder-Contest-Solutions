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
    std::string s;
    std::cin >> s;
    int d;
    std::cin >> d;

    int n = s.length();
    // dp[i][j][k] - total numbers from index i, when the prev sum of digits modulo was j and k is 
    // if the digit selection is bounded by s[i]
    std::vector<std::vector<std::vector<ll>>> dp(n + 1, std::vector<std::vector<ll>>(d, std::vector<ll>(2)));

    for (int i=0;i<d;i++){
        for (int j=0;j<10;j++){
            if (!((i + j) % d))
                dp[n - 1][i][0]++;
        }
        for (int j=0;j<=(s[n - 1]-'0');j++){
            if (!((i + j) % d))
                dp[n - 1][i][1]++;
        }
    }

    for (int i=n-2;i>=0;i--){
        for (int j=0;j<d;j++){
            for (int k=0;k<10;k++){
                int rem = (j + k) % d;
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][rem][0]) % MOD;
                if (k <= (s[i] - '0'))
                    dp[i][j][1] = (dp[i][j][1] + dp[i + 1][rem][(k == (s[i] - '0'))]) % MOD;
            }
        }
    }

    ll ans = (MOD + dp[0][0][1] - 1) % MOD;

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
