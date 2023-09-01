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

    std::vector<std::vector<bool>> dp(k + 1, std::vector<bool>(2, false));
    dp[0][0] = false;
    dp[0][1] = false;

    for (int i=1;i<=k;i++){
        for (int t=0;t<2;t++){
            bool good = false;
            for (int j=0;j<n;j++){
                if (a[j] <= i)
                    good = good || !dp[i - a[j]][1 - t];
            }
            dp[i][t] = good;
        }
    }

    std::cout << (dp[k][0] ? "First\n" : "Second\n");
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
