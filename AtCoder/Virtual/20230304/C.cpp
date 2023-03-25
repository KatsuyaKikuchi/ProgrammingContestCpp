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

bool check(ll n, const vector<bool> &U) {
    while (n > 0) {
        ll t = n % 10;
        n /= 10;
        if (!U[t])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<bool> U(10, true);
    REP(i, K) {
        ll t;
        cin >> t;
        U[t] = false;
    }

    while (true) {
        if (check(N, U))
            break;
        N++;
    }
    cout << N << endl;
    return 0;
}