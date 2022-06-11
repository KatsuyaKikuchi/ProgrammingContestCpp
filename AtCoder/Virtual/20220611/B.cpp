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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    {
        vector<vector<ll>> B(H, vector<ll>(W, 0));
        REP(i, H) {
            REP(j, W) {
                if (j > 0)
                    B[i][j] += B[i][j - 1];
                if (S[i][j] == '#')
                    B[i][j] = 0;
                else
                    B[i][j]++;
                A[i][j] += B[i][j];
            }
        }
    }
    {
        vector<vector<ll>> B(H, vector<ll>(W, 0));
        REP(i, H) {
            for (ll j = W - 1; j >= 0; --j) {
                if (j < W - 1)
                    B[i][j] += B[i][j + 1];
                if (S[i][j] == '#')
                    B[i][j] = 0;
                else
                    B[i][j]++;
                A[i][j] += B[i][j];
            }
        }
    }
    {
        vector<vector<ll>> B(H, vector<ll>(W, 0));
        REP(j, W) {
            REP(i, H) {
                if (i > 0)
                    B[i][j] += B[i - 1][j];
                if (S[i][j] == '#')
                    B[i][j] = 0;
                else
                    B[i][j]++;
                A[i][j] += B[i][j];
            }
        }
    }
    {
        vector<vector<ll>> B(H, vector<ll>(W, 0));
        REP(j, W) {
            for (ll i = H - 1; i >= 0; --i) {
                if (i < H - 1)
                    B[i][j] += B[i + 1][j];
                if (S[i][j] == '#')
                    B[i][j] = 0;
                else
                    B[i][j]++;
                A[i][j] += B[i][j];
            }
        }
    }
    ll K = 0;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.') {
                A[i][j] -= 3;
                K++;
            }
        }
    }

    mint ans = 0;
    mint p = ((mint) 2).pow(K);
    REP(i, H) {
        REP(j, W) {
            ll n = K - A[i][j];
            ans += p - ((mint) 2).pow(n);
        }
    }
    cout << ans.value() << endl;

    return 0;
}