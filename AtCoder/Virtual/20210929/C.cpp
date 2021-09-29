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

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, K;
    cin >> N >> K;
    ll n = (N - 1) * (N - 2) / 2;
    if (n < K) {
        cout << -1 << endl;
        return 0;
    }

    vector<pll> E;
    FOR(i, N, 1) {
        E.push_back(pll(0, i));
        ll cnt = i - 1;
        while (K - cnt < 0) {
            E.push_back(pll(cnt, i));
            cnt--;
        }
        K -= cnt;
    }

    cout << E.size() << endl;
    REP(i, E.size()) {
        cout << E[i].first + 1 << " " << E[i].second + 1 << endl;
    }
    return 0;
}