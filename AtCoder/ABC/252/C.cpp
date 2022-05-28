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
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = INF;
    REP(n, 10) {
        ll t = 0;
        ll count = 0;
        vector<bool> used(N, false);
        while (count < N) {
            REP(i, N) {
                if (used[i])
                    continue;
                if (S[i][t % 10] - '0' == n) {
                    used[i] = true;
                    count++;
                    break;
                }
            }
            t = (t + 1);
        }
        ans = std::min(ans, t - 1);
    }
    cout << ans << endl;
    return 0;
}