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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> D;
    std::map<ll, ll> mp;
    ll n = 1;
    while (n * n <= N) {
        if (N % n == 0) {
            ll m = N / n;
            mp[n] = D.size();
            D.emplace_back(n, INF);
            if (m != n) {
                mp[m] = D.size();
                D.emplace_back(pll(m, INF));
            }
        }
        n++;
    }
    REP(i, M) {
        ll a, c;
        cin >> a >> c;
        ll g = gcd(a, N);
        ll index = mp[g];
        D[index].second = std::min(D[index].second, c);
    }
    sort(D.begin(), D.end(), [](pll a, pll b) { return a.second < b.second; });
    ll ans = 0;
    for (auto &d: D) {
        if (d.second == INF)
            break;
        ll g = gcd(d.first, N);
        if (g < N) {
            ans += g * d.second * (N / g - 1);
            N = g;
        }
    }

    if (N > 1)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}