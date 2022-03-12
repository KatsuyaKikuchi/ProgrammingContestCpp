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
    ll N;
    cin >> N;
    vector<ll> A(N);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    REP(i, N) {
        cin >> A[i];
        q.push(pll(A[i], i));
    }

    vector<ll> ans(N, 0);
    vector<bool> seen(N, false);

    ll m = 0;
    REP(i, N) {
        if (seen[i])
            continue;
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            seen[t.second] = true;
            ans[i] += t.first - m;
            if (t.second != i) {
                continue;
            }
            ans[i] += (q.size()) * (A[i] - m);
            break;
        }
        m = std::max(m, A[i]);
    }

    REP(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}