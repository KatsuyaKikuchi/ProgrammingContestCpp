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

ll num(ll bit, ll n) {
    REP(i, n) {
        bit /= 3;
    }
    return bit % 3;
}

ll add(ll bit, ll n) {
    ll sum = 1;
    REP(i, n) {
        sum *= 3LL;
    }

    return bit + sum;
}

ll resize(ll bit, ll n) {
    ll ret = 0;
    ll m = 1;
    REP(i, n) {
        ret += m * (bit % 3);
        bit /= 3;
        m *= 3LL;
    }
    return ret;
}

ll NXT[200005][15];
bool RESIZE[200005][15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    M++;
    vector<vector<mint>> dp(M);
    REP(m, M) {
        ll p = pow(3LL, m);
        REP(bit, p) {
            dp[m].push_back(0);
        }
    }
    dp[M - 1][0] = 1;
    REP(bit, pow(3LL, M)) {
        REP(i, M) {
            RESIZE[bit][i] = false;
            ll count = 0;
            REP(j, i) {
                count = std::max(count, num(bit, j));
            }
            ll b = num(bit, i);
            if (b > count) {
                NXT[bit][i] = bit;
            } else {
                if (count == 2) {
                    RESIZE[bit][i] = true;
                    NXT[bit][i] = resize(bit, i);
                } else {
                    ll nxt = bit;
                    REP(_, count + 1 - b) {
                        nxt = add(nxt, i);
                    }
                    NXT[bit][i] = nxt;
                }
            }
        }
    }

    REP(i, N) {
        vector<vector<mint>> tmp(M);
        REP(m, M) {
            ll p = pow(3LL, m);
            tmp[m].assign(p, 0);
            REP(bit, p) {
                REP(n, m) {
                    ll nxt_bit = NXT[bit][n];
                    if (RESIZE[bit][n])
                        tmp[n][nxt_bit] += dp[m][bit];
                    else
                        tmp[m][nxt_bit] += dp[m][bit];
                }
                if (m < M - 1)
                    tmp[m][bit] += dp[m][bit];
            }
        }

        swap(dp, tmp);
    }

    mint ans = 0;
    REP(i, M - 1) {
        ll p = pow(3LL, i);
        REP(bit, p) {
            ans += dp[i][bit];
        }
    }
    cout << ans.value() << endl;
    return 0;
}