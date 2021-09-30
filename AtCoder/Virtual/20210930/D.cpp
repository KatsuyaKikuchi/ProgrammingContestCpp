#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <map>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> C(N);
    REP(i, N) {
        cin >> C[i];
        C[i]--;
    }

    vector<ll> T(N);
    vector<vector<ll>> U(N);
    vector<std::map<ll, ll>> MP(N);
    REP(i, N) {
        T[i] = i;
        U[i].push_back(i);
        MP[i][C[i]] = 1;
    }

    REP(_, Q) {
        ll t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            ll p0 = T[a];
            ll p1 = T[b];
            if (p0 == p1)
                continue;
            if (U[p0].size() < U[p1].size()) {
                REP(i, U[p0].size()) {
                    T[U[p0][i]] = p1;
                    U[p1].push_back(U[p0][i]);
                    MP[p1][C[U[p0][i]]]++;
                }
                U[p0].clear();
            } else {
                REP(i, U[p1].size()) {
                    T[U[p1][i]] = p0;
                    U[p0].push_back(U[p1][i]);
                    MP[p0][C[U[p1][i]]]++;
                }
                U[p1].clear();
            }
        } else {
            ll p = T[a];
            cout << MP[p][b] << endl;
        }

#if false
        REP(i, N) {
            REP(j, U[i].size()) {
                cout << U[i][j] << " ";
            }
            cout << endl;
        }
        cout << "--" << endl;
#endif
    }

    return 0;
}