#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> S(2, vector<ll>(N + 5, 0));
    REP(i, N) {
        ll c, p;
        cin >> c >> p;
        c--;
        S[c][i + 1] = p;
    }
    REP(i, N) {
        S[0][i + 1] += S[0][i];
        S[1][i + 1] += S[1][i];
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll l, r;
        cin >> l >> r;
        l--;
        ll a = S[0][r] - S[0][l];
        ll b = S[1][r] - S[1][l];
        cout << a << " " << b << endl;
    }
    return 0;
}