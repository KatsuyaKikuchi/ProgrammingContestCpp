#include <bits/stdc++.h>
#include "atcoder/all"

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

using S = mint;
using F = mint;

S op(S a, S b) {
    return a + b;
}

S e() {
    return 0;
}

S mapping(F f, S s) {
    return s * f;
}

F comp(F f, F g) {
    return f * g;
}

F id() {
    return 1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> X;
    REP(i, N) {
        cin >> A[i];
        X.push_back(A[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    atcoder::lazy_segtree<mint, op, e, F, mapping, comp, id> seg(X.size() + 5);

    mint ans = 0;
    REP(i, N) {
        ll index = lower_bound(X.begin(), X.end(), A[i]) - X.begin();

        mint x = seg.prod(0, index + 1);
        ans += x;

        mint t = seg.get(index);
        seg.set(index, t + 1);
        seg.apply(0, X.size() + 3, 2);
    }
    ans /= 2;
    cout << ans.value() << endl;

    return 0;
}