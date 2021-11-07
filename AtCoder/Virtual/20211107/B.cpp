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
    string S;
    cin >> S;
    ll N = S.length();
    ll s = 0;
    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    reverse(S.begin(), S.end());
    ll p = 1;
    REP(i, N) {
        s += (S[i] - '0') * p;
        s %= 2019;
        p = (p * 10) % 2019;
        ans += mp[s];
        mp[s]++;
    }
    cout << ans << endl;
    return 0;
}