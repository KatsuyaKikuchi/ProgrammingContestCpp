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

ll x[4] = {0, 1, 0, -1};
ll y[4]{1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.')
                continue;
            if (S[i - 1][j] == '.') {
                if (S[i - 1][j - 1] == '#' ||
                    (S[i - 1][j - 1] == '.' && S[i][j - 1] == '.'))
                    ans++;
            }
            if (S[i + 1][j] == '.') {
                if (S[i + 1][j - 1] == '#' ||
                    (S[i + 1][j - 1] == '.' && S[i][j - 1] == '.'))
                    ans++;
            }
            if (S[i][j - 1] == '.') {
                if (S[i - 1][j - 1] == '#' ||
                    (S[i - 1][j - 1] == '.' && S[i - 1][j] == '.'))
                    ans++;
            }
            if (S[i][j + 1] == '.') {
                if (S[i - 1][j + 1] == '#' ||
                    (S[i - 1][j + 1] == '.' && S[i - 1][j] == '.'))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}