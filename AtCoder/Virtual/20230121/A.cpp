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
    ll sum = 0;
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            mp[x - sum]++;
        } else if (t == 2) {
            ll x;
            cin >> x;
            sum += x;
        } else {
            auto it = mp.begin();
            while (it != mp.end()) {
                if (it->second > 0)
                    break;
                mp.erase(it);
                it++;
            }
            cout << it->first + sum << endl;
            it->second--;
        }
    }
    return 0;
}