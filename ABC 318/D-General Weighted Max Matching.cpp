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

    struct Edge{
        int u;
        int v;
        ll w;
    };

    std::vector<std::vector<int>> adj(n, std::vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int w;
            std::cin >> w;
            adj[i][j] = w;
            adj[j][i] = w;
        }
    }

    std::vector<ll> dp(1 << n, -1);

    auto solve = [&](int mask, const auto& solve) -> ll {
        if (dp[mask] != -1)
            return dp[mask];
        
        ll curr = 0;
        std::vector<int> not_taken;
        for (int i=0;i<n;i++){
            if (!(mask & (1 << i)))
                not_taken.push_back(i);
        }

        int m = not_taken.size();
        for (int i=0;i<m;i++){
            for (int j=i+1;j<m;j++){
                curr = std::max(curr, adj[not_taken[i]][not_taken[j]] + solve(mask | (1 << not_taken[i]) | (1 << not_taken[j]), solve));
            }
        }

        return dp[mask] = curr;
    };

    std::cout << solve(0, solve) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

/*

*/
