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
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    ll a = 0, b = 0;
    REP(i, N) {
        if (A[i] == B[i])a++;
    }
    REP(i, N) {
        REP(j, N) {
            if (A[i] == B[j]) {
                b++;
                break;
            }
        }
    }
    b -= a;
    cout << a << endl;
    cout << b << endl;
    return 0;
}