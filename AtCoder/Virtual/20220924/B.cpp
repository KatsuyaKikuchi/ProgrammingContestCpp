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
    ll N, K;
    cin >> N >> K;
    vector<ll> C(N);
    REP(i, N) {
        cin >> C[i];
    }
    ll count = 0;
    std::map<ll, ll> m;
    REP(i, K) {
        m[C[i]]++;
        if (m[C[i]] == 1)
            count++;
    }
    ll ans = count;
    FOR(i, N, K) {
        m[C[i - K]]--;
        if (m[C[i - K]] == 0)
            count--;
        m[C[i]]++;
        if (m[C[i]] == 1)
            count++;
        ans = std::max(ans, count);
    }

    cout << ans << endl;
    return 0;
}