#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if ((r & 1) == 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

int main() {
    ll N, D;
    cin >> N >> D;
    ll ans = 0;
    ll n = 1;
    ll div = modpow(2, MOD - 2);
    REP(i, N) {
        ll max = std::min(D - 1, i);
        ll min = std::max(1LL, (i + D - N + 2) / 2);
        if (min <= max) {
            ll sum = (MOD + modpow(2, D - min + 1) - modpow(2, D - max)) % MOD;
            ans += (((n * sum) % MOD) * div) % MOD;
        }
        if (i + D < N) {
            ans += n * modpow(2, D);
        }
        if (i >= D) {
            ans += n;
        }
        n = (n * 2LL) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}