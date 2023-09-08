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

vector<string> cut(vector<string> A) {
    vector<string> ret;
    pll w(INF, -INF), h(INF, -INF);
    ll H = A.size();
    REP(i, H) {
        REP(j, A[i].size()) {
            if (A[i][j] == '#') {
                w.first = std::min(w.first, j);
                w.second = std::max(w.second, j);
                h.first = std::min(h.first, i);
                h.second = std::max(h.second, i);
            }
        }
    }
    FOR(i, h.second + 1, h.first) {
        string s;
        FOR(j, w.second + 1, w.first) {
            s.push_back(A[i][j]);
        }
        ret.push_back(s);
    }
    return ret;
}

bool check(const vector<string> &A, const vector<string> &B, const vector<string> &X, pll a, pll b, pll x) {
    if (a.first + A.size() > 10 || a.second + A[0].size() > 10 ||
        b.first + B.size() > 10 || b.second + B[0].size() > 10 ||
        x.first + X.size() > 10 || x.second + X[0].size() > 10)
        return false;

    vector<string> M(10);
    REP(i, 10) {
        REP(j, 10) {
            M[i].push_back('.');
        }
    }
    REP(i, A.size()) {
        REP(j, A[i].size()) {
            if (A[i][j] == '#')
                M[i + a.first][j + a.second] = '#';
        }
    }
    REP(i, B.size()) {
        REP(j, B[i].size()) {
            if (B[i][j] == '#')
                M[i + b.first][j + b.second] = '#';
        }
    }


    REP(i, X.size()) {
        REP(j, X[i].size()) {
            if (M[x.first + i][x.second + j] != X[i][j])
                return false;
            M[x.first + i][x.second + j] = '.';
        }
    }
    REP(i, 10) {
        REP(j, 10) {
            if (M[i][j] == '#')
                return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<string> A, B, X;
    {
        ll H, W;
        cin >> H >> W;
        A.resize(H);
        REP(i, H) {
            cin >> A[i];
        }
        A = cut(A);
    }
    {
        ll H, W;
        cin >> H >> W;
        B.resize(H);
        REP(i, H) {
            cin >> B[i];
        }
        B = cut(B);
    }
    {
        ll H, W;
        cin >> H >> W;
        X.resize(H);
        REP(i, H) {
            cin >> X[i];
        }
        X = cut(X);
    }

    ll MH = 10, MW = 10;
    REP(i, 10) {
        REP(j, 10) {
            REP(a, 10) {
                REP(b, 10) {
                    REP(x, 10) {
                        REP(y, 10) {
                            if (check(A, B, X, pll(i, j), pll(a, b), pll(x, y))) {
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}