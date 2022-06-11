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


struct Query {
    ll D, L, R;
    ll index;
};

struct Data {
    ll index;
    ll R;
};

using mint = ModInt<MOD>;

mint sum(ll left, ll right, mint v) {
    if (left > right)
        return 0;
    mint a = left;
    mint d = 1;
    mint n = right - left + 1;

    mint s = n * (a * 2 + (n - 1) * d) / 2;
    return v * s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<Query> query(Q);
    REP(i, Q) {
        cin >> query[i].D >> query[i].L >> query[i].R;
        query[i].index = i;
    }

    vector<mint> ans(Q, 0);
    std::map<ll, Data> d;
    d[-1] = Data{-1, -1};
    for (ll i = Q - 1; i >= 0; --i) {
        auto q = query[i];
        {
            while (true) {
                auto it = d.lower_bound(q.L);
                if (it == d.end() || it->first > q.R)
                    break;
                ll left = it->first;
                ll right = it->second.R;
                ll index = it->second.index;
                ll date = query[index].D - q.D;

                ans[index] += sum(left, std::min(right, q.R), date);

                d.erase(it);
                if (right > q.R) {
                    d[q.R + 1] = Data{index, right};
                }
            }
        }
        {
            auto it = d.lower_bound(q.L);
            it--;
            if (it->second.index >= 0) {
                ll left = it->first;
                ll right = it->second.R;
                ll index = it->second.index;
                ll date = query[index].D - q.D;

                ans[index] += sum(q.L, std::min(right, q.R), date);

                d.erase(it);
                if (left < q.L) {
                    d[left] = Data{index, q.L - 1};
                }
                if (right > q.R) {
                    d[q.R + 1] = Data{index, right};
                }
            }
        }
        d[q.L] = Data{q.index, q.R};
    }

    for (auto t: d) {
        ll L = t.first, R = t.second.R;
        ll index = t.second.index;
        if (index < 0)
            continue;
        ll D = query[index].D;
        ans[index] += sum(L, R, D);
    }

    REP(i, Q) {
        cout << ans[i].value() << endl;
    }

    return 0;
}