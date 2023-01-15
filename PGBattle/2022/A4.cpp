#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

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

using combination = Combination<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    ll sum = 0;
    combination cmb(20);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        sum += A[i].first * 10LL + A[i].second;
    }

    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    std::map<ll, ll> mp0, mp1;
    {
        mp0[0] = 1;
        REP(i, N / 2) {
            std::map<ll, ll> tmp;
            for (auto s: mp0) {
                REP(j, 11) {
                    ll t = A[i].first * j + s.first;
                    ll n = (s.second * cmb.get(10, j)) % MOD;
                    ll m = (tmp[t] + n) % MOD;
                    tmp[t] = m;
                }
            }
            swap(mp0, tmp);
        }
    }
    {
        mp1[0] = 1;
        FOR(i, N, N / 2) {
            std::map<ll, ll> tmp;
            for (auto s: mp1) {
                REP(j, 11) {
                    ll t = A[i].first * j + s.first;
                    ll n = (s.second * cmb.get(10, j)) % MOD;
                    ll m = (tmp[t] + n) % MOD;
                    tmp[t] = m;
                }
            }
            swap(mp1, tmp);
        }
    }

    ll ans = 0;
    REP(bit, pow(2LL, N)) {
        ll s = 0;
        REP(i, N) {
            if ((bit >> i) & 1) {
                s += A[i].second;
            }
        }
        if (s > sum) {
            continue;
        }
        for (auto t: mp0) {
            ll tmp = s + t.first;
            ll n = t.second;
            ans += (n * mp1[sum - tmp]) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}