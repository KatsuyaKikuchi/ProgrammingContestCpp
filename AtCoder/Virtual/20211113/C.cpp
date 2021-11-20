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
    ll H, W;
    cin >> H >> W;
    vector<ll> C(30, 0);
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) {
            C[s[j] - 'a']++;
        }
    }
    ll a = 0, b = 0, c = 0;
    REP(i, C.size()) {
        a += C[i] / 4;
        C[i] %= 4;
    }
    REP(i, C.size()) {
        b += C[i] / 2;
        C[i] %= 2;
    }
    REP(i, C.size()) {
        c += C[i];
    }
    bool ans = true;
    {
        ll h = H - (H % 2), w = W - (W % 2);
        if (a < (h * w) / 4)
            ans = false;
        a = std::max(0LL, a - (h * w) / 4);
        b += a * 2;
    }
    {
        if (H % 2 == 1) {
            ll w = W - (W % 2);
            if (b < w / 2)
                ans = false;
            b = std::max(0LL, b - w / 2);
        }
        if (W % 2 == 1) {
            ll h = H - (H % 2);
            if (b < h / 2)
                ans = false;
            b = std::max(0LL, b - h / 2);
        }
        c += 2 * b;
    }
    if (H % 2 == 1 && W % 2 == 1) {
        c--;
    }
    if (c > 0) {
        ans = false;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}