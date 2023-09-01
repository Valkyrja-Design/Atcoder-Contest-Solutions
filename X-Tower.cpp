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
    
    struct Block{
        int w;
        int s;
        ll v;
    };

    int mx = 0;
    std::vector<Block> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i].w >> a[i].s >> a[i].v;
        mx = std::max(mx, a[i].s);
    }

    // Exchange arguments trick : https://www.youtube.com/watch?v=7hFWrKa6yRM
    // we sort the blocks in an optimal order in which it is best to take them
    // for two blocks if A is below B then we want
    // s_a > w_b and s_b < w_a or
    // s_a + w_a > s_b + w_b
    std::sort(a.begin(), a.end(), [](const Block& left, const Block& right){
        return left.w + left.s > right.w + right.s;
    });

    // dp[i][j] - max value over the prefix if the allowed weight is j
    // std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(2 * mx + 1, 0));
    // removed first dimension
    std::vector<ll> dp(2 * mx + 1, 0);
    
    for (int i=n-1;i>=0;i--){
        for (int j=2 * mx;j>=1;j--){
            // dp[i][j] = dp[i + 1][j];
            // if (j >= a[i].w)
            //     dp[i][j] = std::max(dp[i][j], dp[i + 1][std::min(a[i].s, j - a[i].w)] + a[i].v);
            if (j >= a[i].w)
                dp[j] = std::max(dp[j], dp[std::min(a[i].s, j - a[i].w)] + a[i].v);
        }
    }

    std::cout << (*std::max_element(dp.begin(), dp.end())) << '\n';
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
