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
    ll N, M;
    cin >> N >> M;
    vector<pll> A(M);
    REP(i, M) {
        cin >> A[i].first;
        A[i].second = 0;
        ll b;
        cin >> b;
        REP(j, b) {
            ll c;
            cin >> c;
            c--;
            A[i].second |= (1LL << c);
        }
    }
    ll p = pow(2LL, N);
    vector<ll> dp(p + 5, INF);
    dp[0] = 0;
    REP(i, M) {
        vector<ll> tmp(p + 5, INF);
        REP(j, p + 1) {
            tmp[j] = std::min(dp[j], tmp[j]);
            ll nxt = (j | A[i].second);
            if (nxt <= p)
                tmp[nxt] = std::min(tmp[nxt], dp[j] + A[i].first);
        }
        swap(dp, tmp);
    }
    ll ans = dp[p - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}