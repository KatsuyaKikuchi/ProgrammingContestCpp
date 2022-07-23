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
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    vector<ll> T(N + 5, true);
    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                ll a = (j - k + N) % N;
                ll b = (i + k + N) % N;
                if (S[i][j] != S[a][b])
                    T[k] = false;
            }
        }
    }

    ll ans = 0;
    REP(a, N) {
        REP(b, N) {
            ll n = (a + b) % N;
            if (T[n])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}