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

    std::vector<std::vector<int>> adj(n);
    for (int i=0;i<n-1;i++){
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // number of ways to color the subtree rooted at v
    // with color of v = black or white
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(2, 1));
    auto dfs = [&](int u, int p, const auto& dfs) -> void {
        bool leaf = adj[u].empty() || (adj[u].size() == 1 && adj[u][0] == p);
        for (int v : adj[u]){
            if (v != p){
                dfs(v, u, dfs);
                dp[u][0] = (dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD)) % MOD;
                dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
            }
        }
    };

    dfs(0, 0, dfs);
    std::cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
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
