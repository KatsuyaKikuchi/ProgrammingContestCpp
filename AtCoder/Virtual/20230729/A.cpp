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
    string S;
    cin >> S;
    vector<ll> C(N + 1, 0);
    for (ll i = N - 1; i >= 0; --i) {
        C[i] += C[i + 1];
        if (S[i] == '.')
            C[i]++;
    }

    ll ans = C[0];
    ll count = 0;
    REP(i, N) {
        if (S[i] == '#')
            count++;
        ans = std::min(ans, count + C[i + 1]);
    }
    cout << ans << endl;
    return 0;
}