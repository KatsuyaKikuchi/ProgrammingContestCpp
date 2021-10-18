#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

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
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(M);
    REP(i, M) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    mint ans = 0;
    {
        mint n = N / D;
        mint m = N % D;
        ans = (n * (n + 1)) / 2;
        ans *= D;
        ans += m * (n + 1);
    }

    std::map<ll, ll> mp;
    REP(i, M) {
        ll n = A[i] % D;
        ll p = mp[n];
        mint s = 0;
        if (p != 0) {
            s = (A[i] - p) / D;
        } else {
            s = (A[i] + D - 1) / D;
        }
        ll m = (N - A[i]) / D;
        if (A[i] + m * D > N)
            m--;
        if (A[i] + (m + 1) * D <= N)
            m++;
        ll cnt = m + 1;

        ans -= s * cnt;
        mp[n] = A[i];
    }

    cout << ans.value() << endl;
    return 0;
}