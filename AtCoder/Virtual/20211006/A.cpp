#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll d = 1;
    while (d * d < v.size()) {
        d++;
    }
    vector<pll> D0(d, pll(0, 0)), D1(d * d, pll(0, 0));
    vector<ll> P(N + 5, 1);
    FOR(i, P.size(), 1) {
        P[i] = (P[i - 1] * 2LL) % MOD;
    }
    ll ans = 0;
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        for (ll j = 0; (j + 1) * d <= index; ++j) {
            const pll &d0 = D0[j];
            ans += (d0.first * P[i - d0.second]) % MOD;
        }
        ll base = (index / d) * d;
        for (ll j = 0; j <= (index % d); ++j) {
            const pll &d1 = D1[base + j];
            ans += (d1.first * P[i - d1.second]) % MOD;
        }

        ll sum = 0;
        for (ll j = 0; j < d; ++j) {
            pll &d1 = D1[base + j];
            d1.first = (d1.first * P[i + 1 - d1.second]) % MOD;
            d1.second = i + 1;
            sum += d1.first;
        }
        ans %= MOD;
        D0[index / d] = pll((sum + 1) % MOD, i + 1);
        D1[index].first++;
    }
    cout << ans << endl;
    return 0;
}