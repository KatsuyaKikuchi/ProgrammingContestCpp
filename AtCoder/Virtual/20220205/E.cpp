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

using mint = ModInt<MOD>;
struct Data {
    mint Z = 0;
    mint A = 0;
    mint AB = 0;
    mint ABC = 0;
};

ll check(string s) {
    ll a = 0, b = 0, c = 0;
    REP(i, s.length()) {
        if (s[i] == 'A')
            a++;
        else if (s[i] == 'B')
            b += a;
        else
            c += b;
    }
    return c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    Data d;
    d.Z = 1;
    REP(i, N) {
        Data tmp;
        switch (S[i]) {
            case 'A':
                tmp.Z += d.Z;
                tmp.A += d.A + d.Z;
                tmp.AB += d.AB;
                tmp.ABC += d.ABC;
                break;
            case 'B':
                tmp.Z += d.Z;
                tmp.A += d.A;
                tmp.AB += d.AB + d.A;
                tmp.ABC += d.ABC;
                break;
            case 'C':
                tmp.Z += d.Z;
                tmp.A += d.A;
                tmp.AB += d.AB;
                tmp.ABC += d.ABC + d.AB;
                break;
            case '?':
                tmp.Z = d.Z * 3;

                tmp.A += d.A + d.Z;
                tmp.AB += d.AB;
                tmp.ABC += d.ABC;

               // tmp.Z += d.Z;
                tmp.A += d.A;
                tmp.AB += d.AB + d.A;
                tmp.ABC += d.ABC;

                //tmp.Z += d.Z;
                tmp.A += d.A;
                tmp.AB += d.AB;
                tmp.ABC += d.ABC + d.AB;
                break;
        }
        d = tmp;
    }

    cout << d.ABC.value() << endl;

    return 0;
}