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
    std::vector<std::vector<int>> adj(n);

    for (int i=0;i<m;i++){
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    std::vector<int> d(n, 0);
    std::vector<bool> visited(n, false);
    auto dfs = [&](int u, const auto& dfs) -> void {
        visited[u] = true;
        int curr = 0;
        
        for (int v : adj[u]){
            if (!visited[v])
                dfs(v, dfs);
            curr = std::max(curr, 1 + d[v]);
        }

        d[u] = curr;
    };

    for (int i=0;i<n;i++){
        if (!visited[i])
            dfs(i, dfs);
    }

    std::cout << (*std::max_element(d.begin(), d.end())) << '\n';
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
