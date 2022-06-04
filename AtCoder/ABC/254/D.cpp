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

    ll ans = 0;

    std::map<ll, ll> mp;
    REP(i, N) {
        ll n = i + 1;
        ll m = 2;
        ll p = 1;
        while (m * m <= n) {
            ll count = 0;
            while (n % m == 0) {
                n /= m;
                count++;
            }
            if (count % 2 == 1)
                p *= m;
            m++;
        }

        if (n > 1)
            p *= n;

       // cout << p << endl;

        ans += mp[p] * 2;
        mp[p]++;
    }

    cout << ans + N << endl;

    return 0;
}