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
    ll n, mod;
    std::cin >> n >> mod;

    std::vector<std::vector<int>> adj(n);
    for (int i=0;i<n-1;i++){
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // #ways to color the subtree with root as black
    std::vector<ll> down(n, 1), up(n, 0);
    std::vector<int> parent(n);
    auto dfs = [&](int u, int p, const auto& dfs) -> void {
        parent[u] = p;
        for (int v : adj[u]){
            if (v != p){
                dfs(v, u, dfs);
                down[u] = (down[u] * (down[v] + 1)) % mod;
            }
        }
    };  

    dfs(0, -1, dfs);

    std::vector<ll> ans(n);
    // now we'll calculate the ans for the children of a vertex 
    // while also calculating the #ways for the subtree up
    // that children
    auto ans_dfs = [&](int u, int p, const auto& ans_dfs) -> void {
        ll prefix = 1;  
        std::vector<ll> suffix = {1};
        std::vector<int> children;
        for (int v : adj[u]){
            if (v != p){
                children.push_back(v);
            }
        }
        std::reverse(children.begin(), children.end());

        for (int v : children)
            suffix.push_back((suffix.back() * (down[v] + 1)) % mod);
        
        std::reverse(suffix.begin(), suffix.end());

        // up of current vertex
        auto par = up[u];
        int i = 1;
        for (int v : adj[u]){
            if (v != p){
                // up of children is product of values of siblings and parent's up
                up[v] = ((((par + 1) * prefix)  % mod) * suffix[i]) % mod;
                ans[v] = ((up[v] + 1) * down[v]) % mod;
                prefix = (prefix * (down[v] + 1)) % mod;
                ans_dfs(v, u, ans_dfs);
                i++;
            }
        }
    };  

    ans_dfs(0, -1, ans_dfs);
    ans[0] = down[0];
    for (ll x : ans)   
        std::cout << x << ' ';
    std::cout << '\n';
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
