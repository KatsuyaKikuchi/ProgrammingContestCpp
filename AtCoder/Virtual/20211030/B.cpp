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

ll solve(ll R, ll G, ll B) {
    vector<ll> v = {R, G, B};
    sort(v.begin(), v.end());
    ll ret = INF;
    if ((v[1] - v[0]) % 3 == 0) {
        ret = std::min(ret, v[1]);
    }
    if ((v[2] - v[1]) % 3 == 0) {
        ll x = (v[2] - v[1]) / 3;
        if (x > v[0]) {
            ll d = (x - v[0] + 1) / 2;
            if (v[1] >= d)
                ret = std::min(ret, v[2]);
        } else {
            ret = std::min(ret, v[2]);
        }
    }
    if ((v[2] - v[0]) % 3 == 0) {
        ll x = (v[2] - v[0]) / 3;
        if (x > v[1]) {
            ll d = (x - v[1] + 1) / 2;
            if (v[0] >= d)
                ret = std::min(ret, v[2]);
        } else {
            ret = std::min(ret, v[2]);
        }
    }

    if (ret == INF)
        ret = -1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        ll r, g, b;
        cin >> r >> g >> b;
        cout << solve(r, g, b) << endl;
    }
    return 0;
}