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

struct Data {
    ll s, t, c;
};

int main() {
    ll N, C;
    cin >> N >> C;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].s >> D[i].t >> D[i].c;
        D[i].c--;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.s < b.s; });
    REP(c, C) {
        bool suc = true;
        vector<pll> V(c + 1, pll(-1, -1));
        REP(i, N) {
            ll n = -1;
            REP(j, V.size()) {
                if (V[j].first == D[i].c && V[j].second <= D[i].s) {
                    n = j;
                    break;
                }
            }
            if (n < 0) {
                REP(j, V.size()) {
                    if (V[j].second < D[i].s) {
                        n = j;
                        break;
                    }
                }
            }
            if (n < 0) {
                suc = false;
                break;
            }
            V[n] = pll(D[i].c, D[i].t);
        }

        if (suc) {
            cout << c + 1 << endl;
            break;
        }
    }
    return 0;
}