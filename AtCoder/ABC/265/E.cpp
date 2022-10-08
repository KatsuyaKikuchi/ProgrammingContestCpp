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
    ll N, M;
    cin >> N >> M;
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    std::set<pll> none;
    REP(i, M) {
        pll p;
        cin >> p.first >> p.second;
        none.insert(p);
    }

    vector<pll> grid;
    grid.push_back(pll(0, 0));
    vector<mint> dp(1, 1);

    vector<pll> T(3);
    T[0] = pll(A, B);
    T[1] = pll(C, D);
    T[2] = pll(E, F);
    REP(i, N) {
        vector<pll> nxt;
        std::map<pll, ll> nxtIndex;
        vector<mint> tmp;
        REP(j, grid.size()) {
            REP(k, 3) {
                ll nx = grid[j].first + T[k].first, ny = grid[j].second + T[k].second;
                pll g(nx, ny);
                if (none.find(g) != none.end())
                    continue;
                auto it = nxtIndex.find(g);
                ll index;
                if (it == nxtIndex.end()) {
                    index = tmp.size();
                    tmp.push_back(0);
                    nxtIndex[g] = index;
                    nxt.push_back(g);
                } else {
                    index = it->second;
                }
                tmp[index] += dp[j];
            }
        }
        swap(dp, tmp);
        swap(grid, nxt);
    }

    mint ans = 0;
    REP(i, dp.size()) {
        ans += dp[i];
    }
    cout << ans.value() << endl;

    return 0;
}