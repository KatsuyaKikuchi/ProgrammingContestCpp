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

struct Primes {
    Primes(int n) {
        primes.clear();
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i])
                continue;
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
};


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

struct PrimeFactory {
    PrimeFactory(int n) {
        primes.clear();
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i])
                continue;
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<pair<int, int>> factorization(long long int n) {
        vector<pair<int, int>> ret;
        for (auto p: primes) {
            int c = 0;
            while (n % p == 0) {
                c++;
                n /= p;
            }
            if (c > 0)
                ret.emplace_back(p, c);
        }
        if (n > 1) {
            ret.emplace_back(n, 1);
        }
        return ret;
    }

    vector<int> primes;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    PrimeFactory primes(100000);
    auto p = primes.factorization(M);

    combination cmb(200005);

    ll ans = 1;
    for (auto t: p) {
        ans = (ans * cmb.get(N + t.second - 1, t.second)) % MOD;
    }

    cout << ans << endl;

    return 0;
}