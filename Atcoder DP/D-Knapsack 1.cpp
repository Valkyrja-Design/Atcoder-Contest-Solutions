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
    int n, w;
    std::cin >> n >> w;
    
    std::vector<std::pair<int, int>> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<long long> dp(w + 1);
    for (int i=0;i<n;i++){
        for (int j=w;j>=1;j--){
            if (a[i].first <= j)
                dp[j] = std::max(dp[j], a[i].second + dp[j - a[i].first]);
        }
    }

    std::cout << dp[w] << '\n';
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
