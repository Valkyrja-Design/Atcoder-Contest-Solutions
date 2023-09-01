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

const int sz = 301;

// dp[i][j][k] - expected number of ops to eat
// everything when the number of count of 1, 2 and
// sushies in dishes is i, j and k respectively
double dp[sz][sz][sz];

void solve(){
    int n;
    std::cin >> n;
     
    std::vector<int> a(n);
    std::vector<int> cnt(4);

    for (int i=0;i<n;i++){
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            for (int k=0;k<sz;k++){
                dp[i][j][k] = -1;
            }
        }
    }

    auto dfs = [&](int i, int j, int k, const auto& dfs) -> double {
        if (!(i + j + k))
            return 0;
        if (dp[i][j][k] > -0.5)
            return dp[i][j][k];

        int total = i + j + k;
        // expected number of ops before selecting 
        // a non-zero number 
        double m = (double)n / total;
        double ret = 0;
        // when the selected non-zero number is a one
        if (i)
            ret += (double)i / total * (dfs(i - 1, j, k, dfs) + m);
        if (j)
            ret += (double)j / total * (dfs(i + 1, j - 1, k, dfs) + m) ;
        if (k)
            ret += (double)k / total * (dfs(i, j + 1, k - 1, dfs) + m);

        return dp[i][j][k] = ret;
    };
    

    std::cout << std::setprecision(10) << dfs(cnt[1], cnt[2], cnt[3], dfs) << '\n';
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
