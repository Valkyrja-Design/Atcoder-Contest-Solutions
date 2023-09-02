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

    std::vector<int> a(n);
    std::map<int, int> suffix;
    for (int i=0;i<n;i++){
        std::cin >> a[i];
        suffix[a[i]]++;
    }
    ll bad = 0;
    for (const auto&[k, v] : suffix){
        bad += (1LL * v * (1LL * v - 1) * (v - 2)) / 6;
    }

    suffix[a[0]]--;
    suffix[a[1]]--;

    std::map<int, int> prefix;
    prefix[a[0]] = 1;
    auto sum = 1LL * prefix[a[0]] * suffix[a[0]];
    auto ans = sum;
    for (int i=2;i<n-1;i++){
        sum -= prefix[a[i]];
        suffix[a[i]]--;
        sum += suffix[a[i - 1]];
        prefix[a[i - 1]]++; 
        ans += sum;
    }

    ans -= bad;
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
