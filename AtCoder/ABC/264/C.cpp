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
ll H0, W0, H1, W1;

ll A[15][15];
ll B[15][15];

bool check(ll b0, ll b1) {
    vector<vector<ll>> T;
    REP(i, H0) {
        if ((b0 >> i) & 1)
            continue;
        vector<ll> t;
        REP(j, W0) {
            if ((b1 >> j) & 1)
                continue;
            t.push_back(A[i][j]);
        }
        T.push_back(t);
    }

    if (H1 != T.size())
        return false;
    if (W1 != T[0].size())
        return false;
    REP(i, H1) {
        REP(j, W1) {
            if (T[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H0 >> W0;
    REP(i, H0) {
        REP(j, W0) {
            cin >> A[i][j];
        }
    }

    cin >> H1 >> W1;
    REP(i, H1) {
        REP(j, W1) {
            cin >> B[i][j];
        }
    }

    REP(b0, pow(2LL, H0)) {
        REP(b1, pow(2LL, W0)) {
            if (check(b0, b1)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}