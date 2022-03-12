#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 2e18;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;

    std::map<ll, ll> mp;
    mp[-1] = 0;
    mp[INF] = 0;

    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            mp[x]++;
        } else if (t == 2) {
            ll x, k;
            cin >> x >> k;
            auto it = mp.find(x);
            bool erase = false;
            if (it == mp.end()) {
                erase = true;
                mp[x] = 0;
                it = mp.find(x);
            }
            bool e = false;
            ll count = 0;
            REP(_, k + 5) {
                count += it->second;
                if (count >= k) {
                    cout << it->first << endl;
                    e = true;
                    break;
                }
                it--;
                if (it->first == -1) {
                    break;
                }
            }

            if (!e)
                cout << -1 << endl;

            if (erase) {
                it = mp.find(x);
                mp.erase(it);
            }

        } else {
            ll x, k;
            cin >> x >> k;

            auto it = mp.find(x);
            bool erase = false;
            if (it == mp.end()) {
                erase = true;
                mp[x] = 0;
                it = mp.find(x);
            }
            bool e = false;
            ll count = 0;
            REP(_, k + 5) {
                count += it->second;
                if (count >= k) {
                    cout << it->first << endl;
                    e = true;
                    break;
                }
                it++;
                if (it->first == INF) {
                    break;
                }
            }

            if (!e)
                cout << -1 << endl;

            if (erase) {
                it = mp.find(x);
                mp.erase(it);
            }

        }
    }
    return 0;
}