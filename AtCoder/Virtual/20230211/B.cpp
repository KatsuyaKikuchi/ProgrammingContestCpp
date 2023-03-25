#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e11;
const long double PI = 3.1415926535897932384626433832795028841971;

vector<ll> T;

void dfs(ll value) {
    if (value >= INF)
        return;
    T.push_back(value);
    ll t = value % 10;
    for (ll i = -1; i <= 1; ++i) {
        if (t + i < 0 || t + i > 9)
            continue;
        ll nxt = value * 10LL + t + i;
        dfs(nxt);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;

    FOR(i, 10, 1) {
        dfs(i);
    }
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    cout << T[K - 1] << endl;
    return 0;
}