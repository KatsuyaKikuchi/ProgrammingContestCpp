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

ll A[35][35];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, i + 1) {
            if (j == 0 || j == i)
                A[i][j] = 1;
            else
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];

            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}