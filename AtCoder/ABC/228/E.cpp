#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n % mod;
    while (r > 0) {
        if ((r & 1) == 1)
            ret = (ret * p) % mod;
        p = (p * p) % mod;
        r /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, M;
    cin >> N >> K >> M;

    if (M % MOD == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll r = modpow(K, N, MOD - 1);
    ll ans = modpow(M, r, MOD);
    cout << ans << endl;
    return 0;
}