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

struct Vertex {
    vector<pll> node;
};

ll E[1005];

using mint = ModInt<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M);
    REP(i, M) {
        cin >> A[i];
        A[i]--;
    }
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.emplace_back(b, i);
        V[b].node.emplace_back(a, i);
    }

    memset(E, 0, sizeof(E));
    REP(i, M - 1) {
        ll s = A[i], g = A[i + 1];
        vector<ll> D(N, INF);
        D[s] = 0;
        queue<ll> q;
        q.push(s);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll cost = D[t] + 1;
            for (auto n: V[t].node) {
                ll nxt = n.first;
                if (D[nxt] <= cost)
                    continue;
                D[nxt] = cost;
                q.push(nxt);
            }
        }

        ll index = g;
        while (index != s) {
            for (auto n: V[index].node) {
                ll nxt = n.first;
                ll e = n.second;
                if (D[index] - 1 != D[nxt])
                    continue;
                index = nxt;
                E[e]++;
            }
        }
    }

    ll MID = 100005;
    vector<mint> dp(MID * 2 + 10, 0);
    dp[MID] = 1;
    REP(i, N - 1) {
        vector<mint> tmp(MID * 2 + 10, 0);
        REP(j, dp.size()) {
            ll b = j - E[i];
            if (b >= 0)
                tmp[b] += dp[j];
            ll r = j + E[i];
            if (r < tmp.size())
                tmp[r] += dp[j];
        }
        swap(dp, tmp);
    }

    cout << dp[MID + K].value() << endl;

    return 0;
}