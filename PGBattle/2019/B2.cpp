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
    ll N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    REP(a, N + 1) {
        ll m = M - a * A;
        ll n = N - a;
        if (m < 0)
            break;
        if (B == C) {
            if (n * B == m) {
                cout << a << " " << n << " " << 0 << endl;
                return 0;
            }
        } else if (B > C) {
            ll t = B - C;
            ll x = m - C * n;
            if (x >= 0 && x % t == 0) {
                ll b = x / t;
                ll c = n - b;
                if (b >= 0 && c >= 0) {
                    cout << a << " " << b << " " << c << endl;
                    return 0;
                }
            }
        } else {
            ll t = C - B;
            ll x = m - B * n;
            if (x >= 0 && x % t == 0) {
                ll c = x / t;
                ll b = n - c;
                if (b >= 0 && c >= 0) {
                    cout << a << " " << b << " " << c << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}