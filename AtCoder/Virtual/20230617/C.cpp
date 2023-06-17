#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

ll solve(ll a, ll b, ll c, ll d) {
    ll ret = INF;
    ret = std::min(ret, std::max(abs(a - b), abs(c - d)));
    ret = std::min(ret, std::max(abs(a - c), abs(b - d)));
    ret = std::min(ret, std::max(abs(a - d), abs(c - b)));
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> R, G, B;
    REP(i, 2 * N) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R')R.push_back(a);
        else if (c == 'G') G.push_back(a);
        else B.push_back(a);
    }

    sort(R.begin(), R.end());
    sort(G.begin(), G.end());
    sort(B.begin(), B.end());

    if (R.size() % 2 == 0 && G.size() % 2 == 0 && B.size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (R.size() % 2 == 0)
        swap(R, B);
    else if (G.size() % 2 == 0)
        swap(G, B);

    ll ans = INF;
    REP(i, R.size()) {
        ll index = lower_bound(G.begin(), G.end(), R[i]) - G.begin();
        if (index - 1 >= 0)
            ans = std::min(ans, abs(R[i] - G[index - 1]));
        if (index < G.size())
            ans = std::min(ans, abs(R[i] - G[index]));
        if (index + 1 < G.size())
            ans = std::min(ans, abs(R[i] - G[index + 1]));
    }
    if (B.size() >= 2) {
        ll mr = INF;
        REP(i, R.size()) {
            ll index = lower_bound(B.begin(), B.end(), R[i]) - B.begin();
            if (index - 1 >= 0)
                mr = std::min(mr, abs(R[i] - B[index - 1]));
            if (index < B.size())
                mr = std::min(mr, abs(R[i] - B[index]));
            if (index + 1 < B.size())
                mr = std::min(mr, abs(R[i] - B[index + 1]));
        }
        ll mg = INF;
        REP(i, G.size()) {
            ll index = lower_bound(B.begin(), B.end(), G[i]) - B.begin();
            if (index - 1 >= 0)
                mg = std::min(mg, abs(G[i] - B[index - 1]));
            if (index < B.size())
                mg = std::min(mg, abs(G[i] - B[index]));
            if (index + 1 < B.size())
                mg = std::min(mg, abs(G[i] - B[index + 1]));
        }
        ans = std::min(ans, mr + mg);
    }
    cout << ans << endl;

    return 0;
}