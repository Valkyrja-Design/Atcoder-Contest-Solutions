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
    int n;
    std::cin >> n;
    
    struct Happy{
        int a;
        int b;
        int c;
    };
    std::vector<Happy> a(n);
    
    for (int i=0;i<n;i++){
        std::cin >> a[i].a >> a[i].b >> a[i].c;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(3, INT_MAX));
    dp[n - 1] = {std::max(a[n - 1].b, a[n - 1].c), std::max(a[n - 1].a, a[n - 1].c), std::max(a[n -1].a, a[n - 1].b)};

    for (int i=n-2;i>=0;i--){
        dp[i][0] = std::max(a[i].b + dp[i + 1][1], a[i].c + dp[i + 1][2]);
        dp[i][1] = std::max(a[i].a + dp[i + 1][0], a[i].c + dp[i + 1][2]);
        dp[i][2] = std::max(a[i].a + dp[i + 1][0], a[i].b + dp[i + 1][1]);
    }

    std::cout << std::max({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
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
