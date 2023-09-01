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

class Matrix{
    public:
        explicit Matrix(int n) : m(n, std::vector<ll>(n)), n(n) {
            for (int i=0;i<n;i++){
                m[i][i] = 1;
            }
        }
        explicit Matrix(int n, int k) : m(n, std::vector<ll>(n, k)), n(n) {}

        Matrix operator*(const Matrix& other) {
            Matrix mtx{n, 0};

            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    // m[i][j] = sum(m[i][k] * other[k][j]);
                    for (int k=0;k<n;k++){
                        mtx[i][j] = (mtx[i][j] + (m[i][k] * other[k][j]) % MOD) % MOD; 
                    }
                }
            }

            return mtx;
        }

        const std::vector<ll>& operator[](size_t i) const {
            return m[i];
        }
        std::vector<ll>& operator[](size_t i){
            return m[i];
        }

    public:
        std::vector<std::vector<ll>> m;
        int n;
};

std::istream& operator>>(std::istream& in, Matrix& m){
    for (int i=0;i<m.n;i++){
        for (int j=0;j<m.n;j++){
            std::cin >> m[i][j];
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrix& m){
    for (int i=0;i<m.n;i++){
        for (int j=0;j<m.n;j++){
            std::cout << m[i][j] << ' '; 
        }
        std::cout << '\n';
    }

    return out;
}

Matrix bin_exp(Matrix m, ll k){
    Matrix ret{m.n};
    while (k){
        if (k&1) ret = (ret * m);
        k >>= 1;
        m = (m * m);
    }

    return ret;
}

void solve(){
    int n;
    ll k;
    std::cin >> n >> k;

    Matrix m{n, 0};
    std::cin >> m;

    // #paths is simply sum of all entries of (adj_matrix) ^ k
    m = bin_exp(m, k);
    ll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ans = (ans + m[i][j]) % MOD;
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
}

/*

*/
