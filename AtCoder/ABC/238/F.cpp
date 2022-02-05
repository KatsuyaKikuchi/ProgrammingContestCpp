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
    ll N, K;
    cin >> N >> K;
    vector<pll> P(N);
    REP(i, N) {
        cin >> P[i].first;
        P[i].first--;
    }
    REP(i, N) {
        cin >> P[i].second;
        P[i].second--;
    }
    sort(P.begin(), P.end(), [](pll a, pll b) { return a.first > b.first; });
    vector<vector<vector<mint>>> dp(N + 5, vector<vector<mint>>(K + 5, vector<mint>(N + 5, 0)));

    REP(i, N) {
        dp[i][0][0] = 1;
        REP(j, K + 1) {
            REP(k, N + 1) {
                {
                    // iを入れる
                    dp[i + 1][j + 1][std::max(k, P[i].second)] += dp[i][j][k];
                }
                if (k <= P[i].second) {
                    // iを入れない
                    // 今まで入れてあるXの最小値kがP[i].secondより小さいならば抜いてよい
                    dp[i + 1][j][k] += dp[i][j][k];
                }
            }
        }
    }

    mint ans = 0;
    REP(i, N + 1) {
        ans += dp[N][K][i];
    }
    cout << ans.value() << endl;

    return 0;
}