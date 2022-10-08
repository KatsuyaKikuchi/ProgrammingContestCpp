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
    std::map<ll, ll> mp;
    REP(i, N) {
        ll a;
        cin >> a;
        mp[a]++;
    }

    ll ans = 0;
    while (true) {
        auto mn = mp.begin();
        auto mx = mp.end();
        mx--;
        if (mn == mx && mn->second == 1) {
            break;
        }
        mx->second--;
        if (mx->second == 0)
            mp.erase(mx);
        ll n = mx->first % mn->first;
        if (n > 0) {
            mp[n]++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}