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

mint calc(string &S, ll L) {
    ll N = S.length();
    mint ret = ((mint) N).pow(L);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll MAX = pow(2LL, N);
    vector<mint> dp(MAX, 0);
    for (ll bit = MAX - 1; bit > 0; --bit) {
        string s;
        for (char c = 'a'; c <= 'z'; ++c) {
            bool add = true;
            REP(i, N) {
                if (((bit >> i) & 1) == 0)
                    continue;
                bool e = false;
                REP(j, S[i].length()) {
                    if (S[i][j] == c) {
                        e = true;
                        break;
                    }
                }
                if (!e) {
                    add = false;
                    break;
                }
            }

            if (add)
                s.push_back(c);
        }
        dp[bit] = calc(s, L);
    }

    mint ans = 0;
    for (ll bit = MAX - 1; bit > 0; --bit) {
        ans += dp[bit];
        for (ll sub = bit;; sub = (sub - 1) & bit) {
            if (sub == bit)
                continue;
            dp[sub] -= dp[bit];
            if (sub == 0)
                break;
        }
    }
    cout << ans.value() << endl;
    return 0;
}