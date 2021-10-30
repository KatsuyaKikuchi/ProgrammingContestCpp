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

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

template<std::uint_fast64_t Modulus>
struct Combination {
    using u64 = std::uint_fast64_t;

    explicit Combination(int n) {
        frac.resize(n + 1);
        invFrac.resize(n + 1);
        frac[0] = 1;
        for (int i = 0; i < n; ++i) {
            frac[i + 1] = frac[i] * (i + 1) % Modulus;
        }
        invFrac[n] = inv(frac[n]);
        for (int i = n; i > 0; --i) {
            invFrac[i - 1] = (invFrac[i] * i) % Modulus;
        }
    }

    u64 get(int n, int r) {
        if (n < r)
            return 0;
        return (frac[n] * invFrac[r] % Modulus) * invFrac[n - r] % Modulus;
    }

private:
    u64 inv(u64 n) {
        u64 ret = 1;
        u64 m = Modulus - 2;
        u64 p = n;
        while (m > 0) {
            if ((m & 1) == 1)
                ret = (ret * p) % Modulus;
            m /= 2;
            p = (p * p) % Modulus;
        }
        return ret;
    }

    vector<u64> frac;
    vector<u64> invFrac;
};

using Comb = Combination<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, A, B;
    cin >> N >> M >> A >> B;

    Comb cmb(5000000);
    ll ans = cmb.get(N + M, N);
    if (A > N || B > M) {
        cout << ans << endl;
        return 0;
    }

    ll a0 = cmb.get(A + B, A);
    ll a1 = cmb.get((N - A) + (M - B), N - A);
    ll b = a0 * a1 % MOD;

    cout << (MOD + ans - b) % MOD << endl;

    return 0;
}