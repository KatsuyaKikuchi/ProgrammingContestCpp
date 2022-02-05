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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<pll> A(Q);

    vector<vector<ll>> X(N);
    REP(i, Q) {
        pll a;
        cin >> a.first >> a.second;
        a.first--;
        a.second--;
        X[a.first].push_back(a.second);
    }

    ll right = -1;
    REP(i, N) {
        if (X[i].size() == 0)
            continue;
        sort(X[i].begin(), X[i].end(), [](ll a, ll b) { return a < b; });
        if (right + 1 == i)
            right = X[i][0];
        FOR(j, X[i].size(), 1) {
            if (X[i][j] == X[i][j - 1])
                continue;
            ll nxt = X[i][j - 1] + 1;
            X[nxt].push_back(X[i][j]);
        }
    }

    if (right >= N - 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}