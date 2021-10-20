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

ll gcd(ll a, ll b) {
    if (a < b)
        return gcd(b, a);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}


const ll MAX = 1000000000000000000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    ll x = A / gcd(A, B);
    if (B <= MAX / x)
        cout << B * x << endl;
    else
        cout << "Large" << endl;
    return 0;
}