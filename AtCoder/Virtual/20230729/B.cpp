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
    ll N, Q;
    cin >> N >> Q;
    ll ans = N;
    vector<set<ll>> V(N);
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            if (V[x].empty())
                ans--;
            if (V[y].empty())
                ans--;
            V[x].insert(y);
            V[y].insert(x);
        } else {
            ll x;
            cin >> x;
            x--;
            for (auto n: V[x]) {
                V[n].erase(x);
                if (V[n].empty())
                    ans++;
            }
            if (!V[x].empty())
                ans++;
            V[x].clear();
        }

        cout << ans << endl;
    }
    return 0;
}