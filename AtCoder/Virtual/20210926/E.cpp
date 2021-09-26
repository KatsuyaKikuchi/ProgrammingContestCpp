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
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    REP(i, X) {
        cin >> A[i];
    }
    REP(i, Y) {
        cin >> B[i];
    }
    REP(i, Z) {
        cin >> C[i];
    }
    vector<ll> V;
    REP(i, X) {
        REP(j, Y) {
            V.push_back(A[i] + B[j]);
        }
    }
    sort(V.begin(), V.end(), greater<ll>());
    vector<ll> ans;
    ll size = std::min(K, static_cast<ll>(V.size()));
    REP(i, size) {
        REP(j, Z) {
            ans.push_back(V[i] + C[j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    REP(i, K) {
        cout << ans[i] << endl;
    }
    return 0;
}