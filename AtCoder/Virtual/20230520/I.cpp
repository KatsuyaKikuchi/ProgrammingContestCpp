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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    std::set<pll> s;
    REP(i, N) {
        REP(j, N) {
            if (i == j)
                continue;
            ll dy = A[i].second - A[j].second;
            ll dx = A[i].first - A[j].first;

            ll sx = 1;
            ll sy = 1;
            if (dx != 0)
                sx = dx / abs(dx);
            if (dy != 0)
                sy = dy / abs(dy);
            ll d = 0;
            if (dx == 0)
                d = abs(dy);
            else if (dy == 0)
                d = abs(dx);
            else
                d = gcd(sx * dx, sy * dy);

            pll t = pll(dx / d, dy / d);
            s.insert(t);
        }
    }

    ll ans = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}