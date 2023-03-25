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


template<std::uint_fast64_t Modulus>
class ModInt {
    using u64 = std::uint_fast64_t;
public:
    constexpr ModInt(u64 value = 0) noexcept:
            mValue(value % Modulus) {}

    u64 &value() { return mValue; }

    constexpr ModInt &operator+=(ModInt v) noexcept {
        mValue += v.mValue;
        if (mValue >= Modulus)
            mValue -= Modulus;
        return *this;
    }

    constexpr ModInt &operator-=(ModInt v) noexcept {
        if (mValue < v.mValue)
            mValue += Modulus;
        mValue -= v.mValue;
        return *this;
    }

    constexpr ModInt &operator*=(ModInt v) noexcept {
        mValue = (mValue * v.mValue) % Modulus;
        return *this;
    }

    constexpr ModInt &operator/=(ModInt v) noexcept {
        *this *= v.pow(Modulus - 2);
        return *this;
    }

    constexpr ModInt operator+(ModInt v) noexcept {
        return ModInt(*this) += v;
    }

    constexpr ModInt operator-(ModInt v) noexcept {
        return ModInt(*this) -= v;
    }

    constexpr ModInt operator*(ModInt v) noexcept {
        return ModInt(*this) *= v;
    }

    constexpr ModInt operator/(ModInt v) noexcept {
        return ModInt(*this) /= v;
    }

    ModInt pow(u64 r) {
        u64 p = mValue;
        ModInt ret(1);
        while (r > 0) {
            if (r & 1)
                ret *= p;
            r >>= 1;
            p = (p * p) % Modulus;
        }
        return ret;
    }

private:
    u64 mValue;
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

using mint = ModInt<MOD>;
using mcmb = Combination<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;

    mcmb cmb(3000005);

    mint ans = 0;
    REP(i, X + 2) {
        ll j = (X - 2 * i);
        if (j < 0)
            continue;
        ll y = i + j * 2;
        if (y != Y)
            continue;
        ans += cmb.get(i + 1 + j - 1, j);
    }

    cout << ans.value() << endl;

    return 0;
}