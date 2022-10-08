#include <bits/stdc++.h>

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
    ll X, Y;
    cin >> X >> Y;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<vector<ll>> dp(X + 5, vector<ll>(Y + 5, INF));
    dp[0][0] = 0;
    REP(i, N) {
        vector<vector<ll>> tmp(X + 5, vector<ll>(Y + 5, INF));
        REP(x, X + 1) {
            REP(y, Y + 1) {
                tmp[x][y] = std::min(tmp[x][y], dp[x][y]);
                ll nx = std::min(X, x + A[i].first);
                ll ny = std::min(Y, y + A[i].second);
                tmp[nx][ny] = std::min(tmp[nx][ny], dp[x][y] + 1);
            }
        }
        swap(dp, tmp);
    }

    ll ans = dp[X][Y];
    if (ans >= INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}