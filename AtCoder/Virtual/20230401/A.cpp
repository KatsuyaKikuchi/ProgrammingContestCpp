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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> X;
    REP(i, N) {
        ll s = 0;
        FOR(j, N, i) {
            s += A[j];
            X.push_back(s);
        }
    }
    ll ans = 0;
    for (ll b = 60; b >= 0; --b) {
        ll bit = (1LL << b);
        vector<ll> tmp;
        for (auto x: X) {
            if ((x & bit) > 0)
                tmp.push_back(x);
        }
        
        if (tmp.size() < K)
            continue;
        ans += bit;
        swap(X, tmp);
    }
    cout << ans << endl;
    return 0;
}