#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    vector<ll> A(N);
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
    }
    if (s < L)
        A.push_back(L - s);

    N = A.size();
    sort(A.begin(), A.end(), greater<ll>());

    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a > b; });
    REP(i, N) {
        q.push(A[i]);
    }

    ll ans = 0;
    while (q.size() > 1) {
        ll t0 = q.top();
        q.pop();
        ll t1 = q.top();
        q.pop();
        q.push(t0 + t1);
        ans += t0 + t1;
    }
    cout << ans << endl;

    return 0;
}