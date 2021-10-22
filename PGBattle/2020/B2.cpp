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
    ll N;
    cin >> N;
    string ans = "0.";
    REP(_, N) {
        ans.push_back('0');
    }

    ll p = pow(2LL, N);
    ll index = ans.size() - 1;
    while (p > 0) {
        ll n = p % 10;
        p /= 10;
        ans[index] = (char) (n + '0');
        index--;
    }

    cout << ans << endl;
    return 0;
}