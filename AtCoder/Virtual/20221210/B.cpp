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
    ll H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<ll> C(N + 5, 0);
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            A[i][j]--;
            C[A[i][j]]++;
        }
    }

    REP(i, H - h + 1) {
        vector<ll> tmp(N);
        REP(x, N) {
            tmp[x] = C[x];
        }
        ll count = 0;
        REP(k, h) {
            REP(l, w) {
                tmp[A[i + k][l]]--;
            }
        }
        REP(j, N) {
            if (tmp[j] > 0)
                count++;
        }
        REP(j, W - w) {
            cout << count << " ";
            vector<ll> c(N);
            REP(x, N) {
                c[x] = tmp[x];
            }
            REP(k, h) {
                tmp[A[i + k][j]]++;
                tmp[A[i + k][j + w]]--;
            }
            REP(x, N) {
                if (c[x] > 0 && tmp[x] == 0)
                    count--;
                if (c[x] == 0 && tmp[x] > 0)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}