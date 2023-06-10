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

struct Vertex {
    vector<ll> to;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].to.push_back(b);
    }

    vector<ll> X(N, INF);
    ll ans = -INF;
    REP(i, N) {

        ans = std::max(A[i] - X[i], ans);
        X[i] = std::min(X[i], A[i]);
        for (auto x: V[i].to) {
            X[x] = std::min(X[x], X[i]);
        }
    }

    cout << ans << endl;
    return 0;
}