#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 1000000;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Printer {
    ll C[4];
};

void solve() {
    ll N = 3;
    vector<Printer> P(N);
    REP(i, N) {
        REP(j, 4) {
            cin >> P[i].C[j];
        }
    }

    Printer ans;
    ll sum = 0;
    REP(i, 4) {
        ans.C[i] = INF;
        REP(j, N) {
            ans.C[i] = std::min(ans.C[i], P[j].C[i]);
        }
        sum += ans.C[i];
    }

    if (sum < MAX) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    sum = MAX;

    REP(i, 4) {
        ll o = std::min(sum, ans.C[i]);
        cout << o << " ";
        sum -= o;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}