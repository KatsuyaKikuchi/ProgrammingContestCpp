#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 1000000007;

ll A[105][10];
ll X[8] = {1, 1, 2, 3, 5, 8, 13, 21};

int main() {
    ll H, W, K;
    cin >> H >> W >> K;

    memset(A, 0, sizeof(A));
    A[0][0] = 1;
    REP(i, H) {
        REP(j, W) {
            {
                // そのまま
                ll left = std::max(0LL, j);
                ll right = std::max(0LL, W - 1 - j);
                A[i + 1][j] += A[i][j] * X[left] * X[right];
                A[i + 1][j] %= MOD;
            }
            if (j > 0) {
                // 左
                ll left = std::max(0LL, j - 1);
                ll right = std::max(0LL, W - 1 - j);
                A[i + 1][j - 1] += A[i][j] * X[left] * X[right];
                A[i + 1][j - 1] %= MOD;
            }
            if (j < W - 1) {
                // 右
                ll left = std::max(0LL, j);
                ll right = std::max(0LL, W - 2 - j);
                A[i + 1][j + 1] += A[i][j] * X[left] * X[right];
                A[i + 1][j + 1] %= MOD;
            }
        }
    }

    cout << A[H][K - 1] << endl;

    return 0;
}