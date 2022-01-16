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
    string S[2];
    cin >> S[0] >> S[1];
    ll ans = 3;
    ll n = 1;
    ll p = 0;
    if (S[0][0] == S[0][1]) {
        n++;
        p = 1;
        ans = 6;
    }
    while (n < N) {
        if (S[0][n] == S[1][n]) {
            if (p == 0) {
                ans = (ans * 2) % MOD;
            } else {
            }
            p = 0;
        } else {
            if (p == 0) {
                ans = (ans * 2) % MOD;
            } else {
                ans = (ans * 3) % MOD;
            }
            n++;
            p = 1;
        }
        n++;
    }
    cout << ans << endl;
    return 0;
}