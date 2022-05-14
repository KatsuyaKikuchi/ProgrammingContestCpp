#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 3;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

char C[3] = {'W', 'B', 'R'};

// nCr mod 3
ll comb(ll n, ll r) {
    if (r == 0 || n == r)
        return 1;
    FOR(i, MOD, 1) {
        if (r == i || n - i == r) {
            ll ret = 1;
            REP(j, i) {
                ret *= n - j;
            }
            REP(j, i) {
                ret /= j + 1;
            }
            return ret % MOD;
        }
    }
    return 0;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    string S;
    cin >> N;
    cin >> S;

    ll sum = 0;
    REP(i, N) {
        ll a = comb(N - 1, i);
        ll b = S[i] == C[0] ? 0 : (S[i] == C[1] ? 1 : 2);
        sum += a * b;
        sum %= MOD;
    }

    if (N % 2 == 0) {
        sum = (MOD - sum) % MOD;
    }
    cout << C[sum] << endl;

    return 0;
}