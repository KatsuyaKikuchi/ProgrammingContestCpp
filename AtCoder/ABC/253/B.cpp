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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    pll a, b;
    bool seenA = false;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 'o') {
                if (seenA)
                    a = pll(i, j);
                else
                    b = pll(i, j);
                seenA = true;
            }
        }
    }

    cout << abs(a.first - b.first) + abs(a.second - b.second) << endl;
    return 0;
}