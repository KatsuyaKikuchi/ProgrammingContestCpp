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
    vector<vector<ll>> ans(N, vector<ll>(N));

    REP(i, N) {
        ll s = i * N + 1, e = (i + 1) * N;
        for (ll j = 0; j < N; j += 2) {
            ans[i][j] = s + j / 2;
        }
        for (ll j = 1; j < N; j += 2) {
            ans[i][j] = e - (j / 2);
        }
    }

    REP(i, N) {
        REP(j, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}