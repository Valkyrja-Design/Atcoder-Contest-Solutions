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

    std::vector<std::vector<int>> a(n, std::vector<int>(n));

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            std::cin >> a[i][j];
        }
    }

    // number of matches for set S with first |S| males
    std::vector<ll> dp((1 << n));
    dp[(1 << n) - 1] = 1;

    for (int i=(1<<n)-1;i>=0;i--){
        int sz = __builtin_popcount(i);
        // match the sz-th man with a free woman
        for (int j=0;j<n;j++){
            if (!(i & (1 << j)) && a[sz][j])
                dp[i] = (dp[i] + dp[i | (1 << j)]) % MOD;
        }
    }

    std::cout << dp[0] << '\n';
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
