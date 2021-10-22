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

using mint = ModInt<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll p = pow(2LL, H);

    vector<vector<ll> > mat(p, vector<ll>(p, 0));
    REP(i, p) {
        REP(j, p) {
            bool e = true;
            REP(k, H) {
                if (((i >> k) & 1) == 0 && ((j >> k) & 1) == 0)
                    e = false;
            }
            if (!e)
                continue;
            ll t = (i & j);
            ll cnt = 0;
            REP(k, H) {
                if ((t >> k) & 1)
                    cnt++;
                else {
                    if (cnt % 2 == 1)
                        e = false;
                    cnt = 0;
                }
            }
            if (!e || cnt % 2 == 1)
                continue;
            mat[i][j] = 1;
        }
    }

    vector<mint> dp(p, 0);
    dp[p - 1] = 1;
    REP(i, W) {
        vector<mint> tmp(p, 0);
        REP(n, p) {
            REP(m, p) {
                tmp[n] += dp[m] * mat[n][m];
            }
        }
        swap(dp, tmp);
    }

    cout << dp[p - 1].value() << endl;
    return 0;
}