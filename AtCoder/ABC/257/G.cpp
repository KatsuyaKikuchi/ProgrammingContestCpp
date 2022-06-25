#include <bits/stdc++.h>
#include "atcoder/all"

using namespace atcoder;
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

const ll base0 = 2;
const ll base1 = 37;

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

mint calcHashCore0(ll value, ll t, ll base) {
    mint v = value;
    v *= base;
    v += t;
    return v;
}

mint calcHashCore1(ll value, ll t, ll len, ll base) {
    mint v = value;
    mint x = base;
    v += x.pow(len - 1) * t;
    return v;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    ll ans = INF;
    ll len = 0;
    pll hashS = pll(0, 0), hashT = pll(0, 0);
    vector<pll> L(T.size() + 5, pll(INF, INF));

    auto z = z_algorithm(S);


    L[T.size()] = pll(INF, 0);
    for (ll i = T.size() - 1; i >= 0; --i) {
        // hash計算
        len++;

        if (len > S.size()) {
            break;
        }

        {
            hashS.first = calcHashCore0(hashS.first, S[len - 1], base0).value();
            hashS.second = calcHashCore0(hashS.second, S[len - 1], base1).value();

            hashT.first = calcHashCore1(hashT.first, T[i], len, base0).value();
            hashT.second = calcHashCore1(hashT.second, T[i], len, base1).value();
        }
        if (hashS.first != hashT.first || hashS.second != hashT.second)
            continue;
        ll lent = L[i + len].first;
        ll p = L[i + len].second;
        if (S.size() > len && z[len] >= lent) {
            // lentがz_algorithmの長さ未満
            L[i] = pll(lent + len, p);
        } else {
            L[i] = pll(len, p + 1);
        }
        hashS = pll(0, 0);
        hashT = pll(0, 0);
        len = 0;
    }

    ans = L[0].second;
    if (ans >= INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}