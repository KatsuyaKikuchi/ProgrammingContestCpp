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

bool check(pll a, pll b, pll c) {
    if (a.first == b.first && a.first == c.first)
        return false;
    if (a.second == b.second && a.second == c.second)
        return false;

    pll d0 = pll(a.first - b.first, a.second - b.second);
    pll d1 = pll(a.first - c.first, a.second - c.second);

    return (d0.first * d1.second != d0.second * d1.first);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            FOR(k, N, j + 1) {
                if (check(A[i], A[j], A[k]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}