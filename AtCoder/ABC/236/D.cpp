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

ll N;
ll A[20][20];

ll dfs(const vector<ll> &v, ll value = 0) {
    if (v.size() == 0) {
        return value;
    }
    ll ret = 0;
    FOR(i, v.size(), 1) {
        ll nxt = (value ^ A[v[0]][v[i]]);
        vector<ll> t;
        FOR(j, v.size(), 1) {
            if (j == i)
                continue;
            t.push_back(v[j]);
        }
        ret = std::max(dfs(t, nxt), ret);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 2 * N - 1) {
        FOR(j, 2 * N, i + 1) {
            ll a;
            cin >> a;
            A[i][j] = A[j][i] = a;
        }
    }
    vector<ll> v;
    REP(i, 2 * N) {
        v.push_back(i);
    }

    cout << dfs(v) << endl;

    return 0;
}