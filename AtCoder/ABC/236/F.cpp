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

ll maxBit(ll n) {
    ll ret = 0;
    ll x = 1;
    REP(i, 60) {
        if ((n & x) > 0)
            ret = x;
        x <<= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M = pow(2, N) - 1;
    vector<pll> A(M);
    REP(i, M) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });

    ll ans = 0;
    ll count = 0;
    REP(i, M) {
        if (A[i].second == 0)
            continue;
        ans += A[i].first;

        ll bit = maxBit(A[i].second);
        FOR(j, M, i + 1) {
            if ((bit & A[j].second) > 0)
                A[j].second ^= A[i].second;
        }
    }
     cout << ans << endl;
    return 0;
}