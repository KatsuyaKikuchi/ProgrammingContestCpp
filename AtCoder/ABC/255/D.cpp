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
    ll X;
    ll index;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<Query> q(Q);
    REP(i, Q) {
        cin >> q[i].X;
        q[i].index = i;
    }
    sort(A.begin(), A.end());

    vector<ll> ans(Q);
    sort(q.begin(), q.end(), [](Query a, Query b) { return a.X < b.X; });
    ll value = -INF;
    ll s = 0;
    REP(i, N) {
        s += abs(value - A[i]);
    }

    ll index = 0;
    REP(i, Q) {
        ll v = q[i].X;
        ll nxtIndex = index;
        ll tmp = 0;
        while (nxtIndex < N) {
            if (v <= A[nxtIndex])
                break;
            s -= abs(A[nxtIndex] - value);
            s += abs(A[nxtIndex] - v);
            nxtIndex++;
        }

        s += index * abs(value - v);
        s -= (N - nxtIndex) * abs(value - v);

        ans[q[i].index] = s;
        index = nxtIndex;
        value = v;
    }

    REP(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}