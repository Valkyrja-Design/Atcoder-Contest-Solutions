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
    int n, d;
    std::cin >> n >> d;
    ll p;
    std::cin >> p;

    std::vector<int> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    
    std::vector<ll> prefix(n + 1);
    for (int i=0;i<n;i++){
        prefix[i + 1] = prefix[i] + a[i];
    }

    ll ans = LLONG_MAX;
    for (int i=0;i<=n;i++){
        ans = std::min(ans, prefix[i] + ((n - i + d - 1) / d) *  p);
    }

    std::cout << ans << '\n';
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
