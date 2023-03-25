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

pll calc(ll n) {
    pll t;
    t.second = n % 10;
    ll x = n % 10;
    while (n > 0) {
        x = n % 10;
        n /= 10;
    }
    t.first = x;
    return t;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    std::map<pll, ll> mp;
    REP(i, N) {
        auto t = calc(i + 1);

        mp[t]++;
    }

    ll ans = 0;
    REP(i, N) {
        auto t = calc(i + 1);
        pll x = pll(t.second, t.first);
        ans += mp[x];
    }
    cout << ans << endl;
    return 0;
}