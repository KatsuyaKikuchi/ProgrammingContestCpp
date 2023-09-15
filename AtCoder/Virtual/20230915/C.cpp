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

bool check(vector<string> &A, vector<string> &B, ll x, ll y) {
    ll N = A.size();
    ll M = B.size();
    REP(i, M) {
        REP(j, M) {
            if (A[x + i][y + j] != B[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    REP(i, N) {
        REP(j, N) {
            if (i + M > N || j + M > N)
                continue;

            if (check(A, B, i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}