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

bool seen[505][505];

pll check(char c) {
    if (c == 'U')
        return pll(-1, 0);
    if (c == 'D')
        return pll(1, 0);
    if (c == 'R')
        return pll(0, 1);
    return pll(0, -1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    memset(seen, 0, sizeof(seen));

    pll g(0, 0);
    while (true) {
        if (seen[g.first][g.second]) {
            cout << -1 << endl;
            return 0;
        }
        pll nxt = check(S[g.first][g.second]);
        ll nx = nxt.first + g.first, ny = nxt.second + g.second;
        if (nx < 0 || ny < 0 || nx >= H || ny >= W)
            break;
        seen[g.first][g.second] = true;
        g.first += nxt.first;
        g.second += nxt.second;
    }

    cout << g.first + 1 << " " << g.second + 1 << endl;
    return 0;
}