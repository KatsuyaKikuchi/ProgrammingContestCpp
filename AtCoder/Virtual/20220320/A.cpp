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
    ll n = 0;
    ll t = 1;
    while (n <= N) {
        n += t;
        t++;
        if (n != N)
            continue;

        cout << "Yes" << endl;
        vector<vector<ll>> ans;
        ll x = 1;
        ll index = -1;
        REP(i, t) {
            vector<ll> v;
            REP(j, ans.size()) {
                v.push_back(ans[j][index]);
            }
            while (v.size() < t - 1) {
                v.push_back(x);
                x++;
            }
            ans.push_back(v);
            index++;
        }

        cout << ans.size() << endl;
        REP(i, ans.size()) {
            cout << ans[i].size();
            REP(j, ans[i].size()) {
                cout << " " << ans[i][j];
            }
            cout << endl;
        }

        return 0;
    }
    cout << "No" << endl;
    return 0;
}