#include <bits/stdc++.h>

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
    ll N;
    cin >> N;
    REP(_, N) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        A[r][c] = 0;
        for (ll i = r - 1; i >= 0; --i) {
            if (A[i + 1][c] == 0)
                swap(A[i + 1][c], A[i][c]);
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}