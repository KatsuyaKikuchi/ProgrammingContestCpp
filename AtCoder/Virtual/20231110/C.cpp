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
    ll N, P;
    cin >> N >> P;
    ll n = 2;
    vector<pll> A;
    while (n * n <= P) {
        ll count = 0;
        while (P % n == 0) {
            P /= n;
            count++;
        }
        if (count > 0)
            A.push_back(pll(n, count));
        n++;
    }
    if (P > 1)
        A.push_back(pll(P, 1));

    ll ans = 1;
    REP(i, A.size()) {
        ll t = A[i].second / N;
        ans *= pow(A[i].first, t);
    }
    cout << ans << endl;
    return 0;
}