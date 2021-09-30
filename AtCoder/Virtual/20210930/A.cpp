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

ll modpow(ll n, ll m, ll mod) {
    ll ret = 1;
    ll p = n;
    while (m > 0) {
        if ((m & 1) == 1)
            ret = (ret * p) % mod;
        p = (p * p) % mod;
        m /= 2;
    }
    return ret;
}

template<std::uint_fast64_t Modulus>
struct Combination {
    using u64 = std::uint_fast64_t;

    explicit Combination(int n) {
        frac.resize(n + 1);
        invFrac.resize(n + 1);
        frac[0] = 1;
        for (int i = 0; i < n; ++i) {
            frac[i + 1] = frac[i] * (i + 1) % Modulus;
        }
        invFrac[n] = inv(frac[n]);
        for (int i = n; i > 0; --i) {
            invFrac[i - 1] = (invFrac[i] * i) % Modulus;
        }
    }

    u64 get(int n, int r) {
        if (n < r)
            return 0;
        return (frac[n] * invFrac[r] % Modulus) * invFrac[n - r] % Modulus;
    }

private:
    u64 inv(u64 n) {
        u64 ret = 1;
        u64 m = Modulus - 2;
        u64 p = n;
        while (m > 0) {
            if ((m & 1) == 1)
                ret = (ret * p) % Modulus;
            m /= 2;
            p = (p * p) % Modulus;
        }
        return ret;
    }

    vector<u64> frac;
    vector<u64> invFrac;
};

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;

    Combination<MOD> cmb(N + 10);
    REP(i, K + 1) {
        // M*(M-1)^(N-i)
        ll m = M * modpow(M - 1, N - i - 1, MOD) % MOD;
        ll n = cmb.get(N - 1, i);
        ans += (n * m) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}