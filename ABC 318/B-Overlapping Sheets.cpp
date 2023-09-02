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

    std::vector<std::vector<bool>> covered(101, std::vector<bool>(101, false));
    int ans = 0;
    for (int i=0;i<n;i++){
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        for (int j=a + 1;j<=b;j++){
            for (int k=c + 1;k<=d;k++){
                ans += !covered[j][k]; 
                covered[j][k] = true;
            }
        }
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
