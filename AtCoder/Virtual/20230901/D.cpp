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

bool A[15][15];
ll T;

ll solve(vector<ll> &V) {
    ll N = V.size();
    ll ret = 0;

    return ret;
}

ll dfs(vector<ll> &v) {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> T >> M;
    memset(A, 0, sizeof(A));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = A[b][a] = true;
    }

    vector<ll> V;
    REP(i, N) {
        V.push_back(i);
    }

    ll ans = 0;
    do {
        ans += solve(V);
    } while (next_permutation(V.begin(), V.end()));
    cout << ans << endl;
    return 0;
}