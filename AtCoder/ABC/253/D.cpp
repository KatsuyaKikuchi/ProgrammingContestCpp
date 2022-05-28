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

ll gcd(ll a, ll b) {
    if (a < b)
        return gcd(b, a);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll sum(ll N, ll d) {
    ll n = N / d;
    ll s = n * (2 * d + (n - 1) * d) / 2;
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = N * (N + 1) / 2;

    ll C = A / gcd(A, B) * B;

    ans -= sum(N, A);
    ans -= sum(N, B);
    ans += sum(N, C);

    cout << ans << endl;
    return 0;
}