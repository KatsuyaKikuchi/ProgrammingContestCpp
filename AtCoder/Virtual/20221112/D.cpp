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
    ll ans = -1;
    REP(i, N) {
        bool e = true;
        queue<ll> q;
        q.push(i);
        vector<ll> d(N, -1);
        d[i] = 0;
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll nxt = d[t] + 1;
            REP(j, N) {
                if (S[t][j] == '0')
                    continue;
                if (d[j] < 0) {
                    d[j] = nxt;
                    q.push(j);
                } else {
                    if (abs(d[j] - d[t]) != 1)
                        e = false;
                }
            }
        }
        if (!e)
            continue;
        REP(j, N) {
            ans = std::max(d[j] + 1, ans);
        }
    }

    cout << ans << endl;

    return 0;
}