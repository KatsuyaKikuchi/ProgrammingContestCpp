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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<pll> A(N);
    vector<ll> X, Y;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
        Y.push_back(A[i].second);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    REP(i, N) {
        ll x = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
        ll y = lower_bound(Y.begin(), Y.end(), A[i].second) - Y.begin();
        cout << x + 1 << " " << y + 1 << endl;
    }

    return 0;
}