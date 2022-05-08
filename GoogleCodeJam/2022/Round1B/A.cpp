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

ll solve() {
    ll N;
    cin >> N;
    deque<ll> q;
    REP(i, N) {
        ll a;
        cin >> a;
        q.push_back(a);
    }

    ll ret = 0;
    ll max = -1;
    while (!q.empty()) {
        ll t = INF;
        if (q.front() < q.back()) {
            t = q.front();
            q.pop_front();
        } else {
            t = q.back();
            q.pop_back();
        }

        if (max <= t)ret++;
        max = std::max(max, t);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}