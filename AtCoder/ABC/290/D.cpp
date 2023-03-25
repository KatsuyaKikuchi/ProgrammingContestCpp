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

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    long long c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

//! 方程式 ax = b (mod m) の解xを返す。
//! 見つからなかった場合 -1
long long mod_solver(long long a, long long b, long long m) {
    if (a < 0) {
        a = (m - (abs(a) % m)) % m;
    }
    if (b < 0) {
        b = (m - (abs(b) % m)) % m;
    }
    a %= m;
    b %= m;
    if (b == 0)
        return 0;
    if (a == 0)
        return -1;
    long long g0 = gcd(m, gcd(a, b));
    a /= g0;
    b /= g0;
    m /= g0;
    long long x, y;
    long long g1 = extGCD(a, m, x, y);
    if (g1 != 1) {
        return -1;
    }

    return (m + (b * x) % m) % m;
}

ll solve() {
    ll N, D, K;
    cin >> N >> D >> K;
    ll t = mod_solver(D, -D, N) + 1;
    if (t == 0) {
        return ((K - 1) * D) % N;
    }

    ll count = (K - 1) / t;
    ll n = (K - 1) % t;
    ll start = count;
    //cout << "t:" << t << ",count:" << count << ",start:" << start << ",n:" << n << endl;
    return (start + ((N + n) % N) * D) % N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}