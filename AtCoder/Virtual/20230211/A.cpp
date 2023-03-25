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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X;
    cin >> X;
    vector<ll> T;
    FOR(i, 10, 1) {
        for (ll d = -9; d <= 9; ++d) {
            ll value = 0;
            ll t = i;
            while (value < INF) {
                value = value * 10LL + t;
                T.push_back(value);
                t -= d;
                if (t < 0 || t > 9)
                    break;
            }
        }
    }
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    vector<ll> ans;
    REP(i, T.size()) {
        if (T[i] >= X)
            ans.push_back(T[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

    return 0;
}