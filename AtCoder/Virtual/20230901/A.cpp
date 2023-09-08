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

ll A[15][15];

ll solve(vector<ll> &V) {
    ll ret = 0;
    ll N = V.size();
    REP(i, N - 1) {
        if (A[V[i]][V[i + 1]] < 0)
            break;
        ret += A[V[i]][V[i + 1]];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    memset(A, -1, sizeof(A));
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        A[a][b] = A[b][a] = c;
    }

    ll ans = 0;
    do {
        ans = std::max(ans, solve(v));
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}