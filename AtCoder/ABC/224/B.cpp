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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    bool e = true;
    REP(i, H) {
        REP(j, W) {
            FOR(i2, H, i + 1) {
                FOR(j2, W, j + 1) {
                    if (A[i][j] + A[i2][j2] <= A[i2][j] + A[i][j2])
                        continue;
                    e = false;
                }
            }
        }
    }



    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}