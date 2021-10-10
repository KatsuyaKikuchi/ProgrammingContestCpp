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

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[2005][2005];

ll modpow(ll n, ll m) {
    ll ret = 1;
    ll p = n;
    while (m > 0) {
        if ((m & 1) == 1)
            ret = (ret * p) % MOD;
        m /= 2;
        p = (p * p) % MOD;
    }
    return ret;
}

ll calc(ll n, ll m) {
    ll a = modpow(2LL, m);
    ll b = modpow(2LL, m - n);
    return (a - b + MOD) % MOD;
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    memset(C, 0, sizeof(C));
    REP(i, H) {
        ll n = 0;
        REP(j, W) {
            if (S[i][j] == '#')
                n = 0;
            else
                n++;
            C[i][j] += n;
        }
    }
    REP(i, H) {
        ll n = 0;
        for (ll j = W - 1; j >= 0; --j) {
            if (S[i][j] == '#')
                n = 0;
            else
                n++;
            C[i][j] += n;
        }
    }
    REP(j, W) {
        ll n = 0;
        REP(i, H) {
            if (S[i][j] == '#')
                n = 0;
            else
                n++;
            C[i][j] += n;
        }
    }

    REP(j, W) {
        ll n = 0;
        for (ll i = H - 1; i >= 0; --i) {
            if (S[i][j] == '#')
                n = 0;
            else
                n++;
            C[i][j] += n;
        }
    }

    ll count = H * W;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.')
                C[i][j] -= 3;
            else
                count--;
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ans = (ans + calc(C[i][j], count)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}