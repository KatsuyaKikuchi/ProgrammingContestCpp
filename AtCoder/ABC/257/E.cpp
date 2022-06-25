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
    ll M = 9;
    vector<ll> C(M);
    ll m = INF;
    REP(i, M) {
        cin >> C[i];
        m = std::min(m, C[i]);
    }

    string ans = "";
    while (N >= m) {
        ll c0 = N / m;
        for (ll i = M - 1; i >= 0; --i) {
            if (N < C[i])
                continue;
            ll c1 = (N - C[i]) / m;
            if (c0 > c1 + 1)
                continue;
            ans.push_back('1' + i);
            N -= C[i];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}