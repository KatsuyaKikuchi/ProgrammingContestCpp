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
    ll N;
    cin >> N;
    vector<string> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    bool f = true;
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (A[i][j] == 'D' && A[i][j] != A[j][i]) {
                f = false;
            }
            if (A[i][j] == 'L' && A[j][i] != 'W')
                f = false;
            if (A[i][j] == 'W' && A[j][i] != 'L')
                f = false;
        }
    }

    if (f)
        cout << "correct" << endl;
    else
        cout << "incorrect" << endl;
    return 0;
}