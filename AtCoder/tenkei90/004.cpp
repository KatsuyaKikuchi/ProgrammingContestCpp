#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    vector<ll> h(H, 0), w(W, 0);
    REP(i, H) {
        REP(j, W) {
            h[i] += A[i][j];
            w[j] += A[i][j];
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << h[i] + w[j] - A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}