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

ll A[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    memset(A, 0, sizeof(A));
    REP(_, Q) {
        ll t, a, b;
        cin >> t;
        switch (t) {
            case 1:
                cin >> a >> b;
                a--;
                b--;
                A[a][b] = 1;
                break;
            case 2:
                cin >> a;
                a--;
                REP(i, N) {
                    if (A[i][a] > 0)
                        A[a][i] = 1;
                }
                break;
            case 3:
                cin >> a;
                a--;
                vector<ll> v(N, 0);
                REP(i, N) {
                    if (A[a][i] == 0)
                        continue;
                    REP(j, N) {
                        v[j] += A[i][j];
                    }
                }
                REP(i, N) {
                    if (i != a)
                        A[a][i] = std::max(A[a][i], v[i]);
                }
                break;
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (A[i][j] > 0)
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }
    return 0;
}