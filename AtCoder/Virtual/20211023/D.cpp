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
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> B(N);
    REP(i, N) {
        cin >> B[i].first >> B[i].second;
    }
    sort(B.begin(), B.end(), [](pll a, pll b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    vector<ll> v;
    REP(i, N) {
        v.push_back(B[i].second);
    }
    vector<ll> t(N + 5, INF);
    REP(i, N) {
        ll index = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
        t[index] = v[i];
    }

    ll ans = lower_bound(t.begin(), t.end(), INF) - t.begin();
    cout << ans << endl;
    return 0;
}