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

std::vector<ll> fact(2 * MAXN + 1);
std::vector<ll> inv_fact(2 * MAXN + 1);

ll binomial(int a, int b){
    if (a < 0 || b < 0 || b > a)
        return 0;
    return ((fact[a] * inv_fact[b] % MOD) * inv_fact[a - b]) % MOD;
}

// number of paths from (1, 1) to (x, y) modulo MOD
ll paths(int x, int y){
    return binomial(x + y - 2, y - 1);
}

void solve(){
    fact[0] = inv_fact[0] = 1;
    
    for (int i=1;i<=2*MAXN;i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = (inv_fact[i - 1] * inv(i)) % MOD;
    }

    int h, w, n;
    std::cin >> h >> w >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
    }

    a.push_back({h, w});
    // sorting by their manhattan distance
    std::sort(a.begin(), a.end(), [](const std::pair<int, int>& left, const std::pair<int, int>& right){
        return left.first + left.second < right.first + right.second;
    });

    // number of forbidden paths from (1, 1) such that a[i] is 
    // the first forbidden vertex
    std::vector<ll> dp(n + 1);
    
    for (int i=0;i<=n;i++){
        // total paths to this vertex
        dp[i] = paths(a[i].first, a[i].second);
        // we subtract the paths where we intersect 
        // a vertex previously 
        for (int j=0;j<i;j++){
            if (a[j].first <= a[i].first && a[j].second <= a[i].second){
                // number of paths for which j is the first forbidden vertex 
                // multiplied by the number of paths from vertex j to i
                auto k = (dp[j] * paths(a[i].first - a[j].first + 1, a[i].second - a[j].second + 1)) % MOD;
                dp[i] = (MOD + dp[i] - k) % MOD;
            }
        }
    }

    std::cout << dp[n] << '\n';
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
