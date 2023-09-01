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
    std::string s;
    std::cin >> s;

    // number of permutations for prefix i with last number j (relative to comparison)
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n));
    dp[0][0] = 1;

    for (int i=1;i<n;i++){
        // prefix sums on dp[i - 1][j]
        std::vector<ll> prefix(n + 1);
        for (int j=0;j<n;j++){
            prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % MOD;
        }

        // now we sum when current element is j
        // not actually but comparison wise j-th element
        for (int j=0;j<=i;j++){  
            if (s[i - 1] == '<') dp[i][j] = prefix[j];
            // not prefix[j + 1] because for dp[i -1] we've have i - 1
            // possible values so the allowed numbers (comparison wise)
            // shift left by one 
            else dp[i][j] = (MOD + prefix[n] - prefix[j]) % MOD;
        }
    }

    ll ans = 0;
    for (int i=0;i<n;i++){
        ans = (ans + dp[n - 1][i]) % MOD;
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
