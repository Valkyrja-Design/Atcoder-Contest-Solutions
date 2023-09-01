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

    std::vector<std::vector<ll>> a(n, std::vector<ll>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            std::cin >> a[i][j];
        }
    }

    // score for a set of rabbits
    std::vector<ll> score(1 << n);
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<n;j++){
            if (i & (1 << j)){
                for (int k=j+1;k<n;k++){
                    if (i & (1 << k))
                        score[i] += a[j][k];
                }
            }
        }
    }

    // dp[mask] is the max score if we've already grouped from mask
    std::vector<ll> dp(1 << n);
    // this forms the next group and assigns max score of the resulting mask
    auto recurse = [&](int i, int mask, const std::vector<int>& not_taken, ll prev_score, int group, const auto& recurse) -> void {
        if (i == (int)not_taken.size()){
            dp[mask] = std::max(dp[mask], prev_score + score[group]);
            return;
        }
        recurse(i + 1, mask, not_taken, prev_score, group, recurse);
        recurse(i + 1, mask ^ (1 << not_taken[i]), not_taken, prev_score, group ^ (1 << not_taken[i]), recurse);
    };

    // we iterate over what set of rabbits have already been 
    // distributed into groups and try to form a new group of rabbits 
    // this is actually O(3^n) since each rabbit can in three states - 
    // [already grouped, will group now, will not group]
    for (int i=0;i<(1 << n);i++){
        // set of rabbits which haven't been grouped yet
        std::vector<int> not_taken;
        for (int j=0;j<n;j++){
            if (!(i & (1 << j)))
                not_taken.push_back(j);
        }

        // for a new group with max score
        recurse(0, i, not_taken, dp[i], 0, recurse);
    } 

    // max score when all rabbits have been grouped
    std::cout << dp[(1 << n) - 1] << '\n';
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
