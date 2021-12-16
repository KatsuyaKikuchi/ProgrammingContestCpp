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

struct Data {
    ll a, b, c, d;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    vector<Data> ans;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] % 2 == 0)
                continue;
            if (j < W - 1) {
                A[i][j]--;
                A[i][j + 1]++;
                ans.push_back(Data{i + 1, j + 1, i + 1, j + 2});
            } else if (i < H - 1) {
                A[i][j]--;
                A[i + 1][j]++;
                ans.push_back(Data{i + 1, j + 1, i + 2, j + 1});
            }
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << " " << ans[i].d << endl;
    }

    return 0;
}