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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    mint ans = 0;
    REP(count, N) {
        vector<vector<vector<mint>>> dp(N + 5, vector<vector<mint>>(N + 5, vector<mint>(N + 5, 0)));
        dp[0][0][0] = 1;
        vector<ll> B(N);
        REP(i, N) {
            B[i] = A[i] % (count + 1);
        }
        REP(i, N) {
            REP(j, N + 1) {
                REP(k, N) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    ll nxt = (k + B[i]) % (count + 1);
                    dp[i + 1][j + 1][nxt] += dp[i][j][k];
                }
            }
        }
        ans += dp[N][count + 1][0];
       // cout << ans.value() << endl;
    }

    cout << ans.value() << endl;
    return 0;
}