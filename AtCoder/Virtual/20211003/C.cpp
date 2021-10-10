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

pll get(ll n) {
    ll a = n % 10;
    ll b = n % 10;
    while (n > 0) {
        b = n % 10;
        n /= 10;
    }
    return pll(a, b);
}

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    vector<vector<ll>> V(10, vector<ll>(10, 0));
    REP(a, N) {
        auto p = get(a + 1);
        V[p.first][p.second]++;
    }

    REP(b, N) {
        auto p = get(b + 1);
        ans += V[p.second][p.first];
    }
    cout << ans << endl;
    return 0;
}