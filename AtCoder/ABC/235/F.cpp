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
    string S;
    cin >> S;
    ll N = S.length();
    ll M;
    cin >> M;
    vector<ll> A(10, -1);
    REP(i, M) {
        ll a;
        cin >> a;
        A[a] = i;
    }

    ll b = (1LL << M);

    vector<mint> dpN(b, 0);
    vector<mint> dpS(b, 0);
    FOR(i, S[0] - '0', 1) {
        ll bit = 0;
        if (A[i] >= 0)
            bit |= (1LL << A[i]);
        dpN[bit] += 1;
        dpS[bit] += ((mint) 10).pow(N - 1) * i;
    }

    mint mx = ((mint) 10).pow(N - 1) * (S[0] - '0');
    ll mx_bit = 0;
    if (A[S[0] - '0'] >= 0)
        mx_bit |= (1LL << A[(S[0] - '0')]);
    FOR(i, N, 1) {
        vector<mint> tmpN((1 << M), 0);
        vector<mint> tmpS((1 << M), 0);
        ll m = S[i] - '0';
        mint p = ((mint) 10).pow(N - 1 - i);
        REP(n, 10) {
            ll now_bit = 0;
            if (A[n] >= 0)
                now_bit |= (1LL << A[n]);
            if (m > n) {
                tmpN[now_bit | mx_bit] += 1;
                tmpS[now_bit | mx_bit] += mx + p * n;
            }
            if (n != 0) {
                tmpN[now_bit] += 1;
                tmpS[now_bit] += p * n;
            }

            REP(bit, b) {
                mint num = dpN[bit];
                mint sum = dpS[bit];

                tmpN[now_bit | bit] += num;
                tmpS[now_bit | bit] += p * n * num + sum;
            }
        }
        mx += p * m;
        if (A[m] >= 0)
            mx_bit |= (1LL << A[m]);

        swap(dpN, tmpN);
        swap(dpS, tmpS);
    }

    mint ans = dpS[b - 1];
    if (b - 1 == mx_bit)
        ans += mx;
    cout << ans.value() << endl;

    return 0;
}