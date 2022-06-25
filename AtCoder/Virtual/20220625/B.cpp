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
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });
    REP(i, K) {
        q.push(pll(A[i], i));
    }

    ll ans = INF;
    FOR(i, N, K) {
        while (!q.empty()) {
            pll t = q.top();
            if (A[i] <= t.first)
                break;
            ll count = i - K + K - t.second;
            ans = std::min(ans, count);
            q.pop();
        }
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}