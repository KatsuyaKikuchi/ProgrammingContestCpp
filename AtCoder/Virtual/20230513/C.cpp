
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

struct Query {
    ll a, b, c, d;
};
ll N, M, Q;
vector<Query> q;

ll calc(vector<ll> &A) {
    ll ret = 0;
    REP(i, Q) {
        if (A[q[i].b] - A[q[i].a] == q[i].c)
            ret += q[i].d;
    }
    return ret;
}

ll dfs(vector<ll> &A, ll m = 1, ll max = 0) {
    if (A.size() == N) {
        return std::max(max, calc(A));
    }
    for (int x = m; x <= M; ++x) {
        A.push_back(x);
        max = std::max(dfs(A, x, max), max);
        A.pop_back();
    }
    return max;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    q.resize(Q);
    REP(i, Q) {
        cin >> q[i].a >> q[i].b >> q[i].c >> q[i].d;
        q[i].a--;
        q[i].b--;
    }

    vector<ll> A;
    ll ans = dfs(A);
    cout << ans << endl;
    return 0;
}