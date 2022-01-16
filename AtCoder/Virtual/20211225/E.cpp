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
    if (b > a)
        return gcd(b, a);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll p = 1;
    REP(i, N) {
        cin >> A[i];
        A[i] /= 2;
        ll c = 0;
        while (A[i] % 2 == 0) {
            c++;
            A[i] /= 2;
        }
        p = std::max(p, (ll) pow(2LL, c));
    }

    ll a = p;
    REP(i, N) {
        ll g = gcd(a, A[i]);
        a = (a / g) * A[i];
        if (a > M)
            break;
    }

    ll ans = M / a;
    cout << (ans + 1) / 2 << endl;

    return 0;
}