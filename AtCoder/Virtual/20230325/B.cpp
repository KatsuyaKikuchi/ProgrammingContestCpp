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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> P(A), Q(B), R(C);
    REP(i, A) {
        cin >> P[i];
    }
    REP(i, B) {
        cin >> Q[i];
    }
    REP(i, C) {
        cin >> R[i];
    }
    sort(P.begin(), P.end(), [](ll a, ll b) { return a > b; });
    sort(Q.begin(), Q.end(), [](ll a, ll b) { return a > b; });
    sort(R.begin(), R.end(), [](ll a, ll b) { return a > b; });
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    REP(i, X) {
        q.push(P[i]);
    }
    REP(i, Y) {
        q.push(Q[i]);
    }
    REP(i, std::min(X + Y, C)) {
        q.push(R[i]);
    }
    ll ans = 0;
    REP(_, X + Y) {
        ll t = q.top();
        q.pop();
        ans += t;
    }
    cout << ans << endl;
    return 0;
}