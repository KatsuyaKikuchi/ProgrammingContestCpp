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
    double n, m, d;
    cin >> n >> m >> d;

    if (d == 0) {
        cout << OF64 << (m - 1) / n << endl;
    } else {
        cout << OF64 << 2 * d * (m - 1) / (n * n) << endl;
    }


    return 0;
}