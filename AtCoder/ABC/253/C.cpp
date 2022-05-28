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
    ll Q;
    cin >> Q;
    std::map<ll, ll> mp;
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            mp[x]++;
        } else if (t == 2) {
            ll x, c;
            cin >> x >> c;
            auto it = mp.find(x);
            if (it == mp.end())
                continue;
            it->second -= c;
            if (it->second <= 0)
                mp.erase(it);
        } else {
            auto f = mp.begin();
            auto e = mp.end();
            e--;

            cout << e->first - f->first << endl;
        }
    }
    return 0;
}