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
    ll N;
    cin >> N;
    vector<vector<pll>> A(N);
    REP(i, N) {
        ll n;
        cin >> n;
        REP(_, n) {
            ll a, b;
            cin >> a >> b;
            a--;
            A[i].emplace_back(a, b);
        }
    }

    ll ans = 0;
    REP(bit, pow(2LL, N)) {
        bool t = true;
        REP(i, N) {
            bool s = ((bit >> i) & 1) == 1;
            if (!s)
                continue;
            REP(j, A[i].size()) {
                ll a = A[i][j].first;
                ll b = A[i][j].second;

                if ((bit >> a) & 1) {
                    if (b == 0)
                        t = false;
                } else {
                    if (b == 1)
                        t = false;
                }
            }
        }
        if (!t)
            continue;
        ll count = 0;
        REP(i, N) {
            if ((bit >> i) & 1)
                count++;
        }
        ans = std::max(ans, count);
    }
    cout << ans << endl;

    return 0;
}