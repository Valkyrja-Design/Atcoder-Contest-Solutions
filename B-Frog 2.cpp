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
    int n, k = 2;
    std::cin >> n;
    std::cin >> k;  

    std::vector<int> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    std::vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    
    for (int i=n-2;i>=0;i--){
        for (int j=1;i + j < n && j <= k;j++){
            dp[i] = std::min(dp[i], dp[i + j] + std::abs(a[i + j] - a[i]));
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
