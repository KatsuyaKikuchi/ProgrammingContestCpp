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

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n;
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
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    ll ans = 0;
    if (P == 2) {
        REP(i, N) {
            ll n = S[i] - '0';
            if (n % 2 == 0)
                ans += i + 1;
        }
    } else if (P == 5) {
        REP(i, N) {
            if (S[i] == '5' || S[i] == '0')
                ans += i + 1;
        }
    } else {
        std::map<ll, ll> mp;
        mp[0]++;
        ll s = 0;

        ll d = modpow(10, P - 2, P);
        REP(i, N) {
            s = (s * 10 + (S[i] - '0')) % P;
            ll p = s * modpow(d, i + 1, P) % P;
            ans += mp[p];
            mp[p]++;
        }
    }
    cout << ans << endl;

    return 0;
}