#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        REP(j, N) {
            S[i].push_back('.');
        }
    }
    if (N % 3 == 0) {
        REP(i, N) {
            ll w = (i % (N / 3)) * 3;
            REP(j, 3) {
                S[i][j + w] = '#';
            }
        }
    } else if (N % 3 == 1) {
        REP(i, N - 1) {
            ll w = (i % (N / 3)) * 3;
            REP(j, 3) {
                S[i][j + w] = '#';
            }
        }
        REP(i, N) {
            REP(j, 3) {
                S[i][N - 1 - j] = S[i][N - j - 2];
                S[i][N - j - 2] = '.';
            }
        }
        S[N - 1][N - 3] = S[N - 1][N - 4] = S[N - 1][N - 5] = '#';
        S[N - 1][N - 4] = S[N - 2][N - 4] = S[N - 3][N - 4] = '#';
        S[N - 2][N - 3] = S[N - 3][N - 5] = '.';
    } else {
        REP(i, N - 2) {
            ll w = (i % (N / 3)) * 3;
            REP(j, 3) {
                S[i][j + w] = '#';
            }
        }
        REP(i, N) {
            REP(j, 4) {
                S[i][N - 1 - j] = S[i][N - j - 2];
                S[i][N - j - 2] = '.';
            }
        }
        S[N - 1][N - 1] = S[N - 2][N - 1] = S[N - 3][N - 1] = '#';
        S[N - 1][N - 5] = S[N - 2][N - 5] = S[N - 3][N - 5] = '#';
        S[N - 2][N - 4] = S[N - 1][N - 2]  = '#';
        S[N - 3][N - 2] = S[N - 3][N - 4] = '.';
    }
    REP(i, N) {
        cout << S[i] << endl;
    }
    return 0;
}