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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    vector<vector<vector<mint>>> dp(H + 5, vector<vector<mint>>(W + 5, vector<mint>(H + W + 10, 0)));
    if (S[0][0] == 'B') {
        dp[0][0][0] = 1;
    } else if (S[0][0] == 'R') {
        dp[0][0][1] = 1;
    } else {
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
    }

    REP(i, H - 1) {
        REP(j, 2) {
            if (S[i + 1][0] == 'B') {
                dp[i + 1][0][j] += dp[i][0][j];
            } else if (S[i + 1][0] == 'R') {
                dp[i + 1][0][j + 1] += dp[i][0][j];
            } else {
                dp[i + 1][0][j] += dp[i][0][j];
                dp[i + 1][0][j + 1] += dp[i][0][j];
            }
        }
    }
    REP(i, W - 1) {
        REP(j, 2) {
            if (S[0][i + 1] == 'B') {
                dp[0][i + 1][j] += dp[0][i][j];
            } else if (S[0][i + 1] == 'R') {
                dp[0][i + 1][j + 1] += dp[0][i][j];
            } else {
                dp[0][i + 1][j] += dp[0][i][j];
                dp[0][i + 1][j + 1] += dp[0][i][j];
            }
        }
    }

    FOR(i, H, 1) {
        FOR(j, W, 1) {
            REP(k, H + W + 5) {
                if (S[i][j] == 'B') {
                    dp[i][j][k] += dp[i - 1][j][k] * dp[i][j - 1][k];
                } else if (S[i][j] == 'R') {
                    dp[i][j][k + 1] = dp[i - 1][j][k] * dp[i][j - 1][k];
                } else {
                    dp[i][j][k] += dp[i - 1][j][k] * dp[i][j - 1][k];
                    dp[i][j][k + 1] = dp[i - 1][j][k] * dp[i][j - 1][k];
                }
            }
        }
    }

#if false
    REP(i, H) {
        REP(j, W) {
            cout << "(";
            REP(k, H + W + 1) {
                cout << dp[i][j][k].value() << ",";
            }
            cout << "), ";
        }
        cout << endl;
    }
#endif

    mint ans = 0;
    REP(i, H + W + 5) {
        ans += dp[H - 1][W - 1][i];
    }
    cout << ans.value() << endl;

    return 0;
}