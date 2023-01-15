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
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<string> ans(H);
    REP(i, B) {
        REP(j, A) {
            ans[i].push_back('1');
        }
        FOR(j, W, A) {
            ans[i].push_back('0');
        }
    }
    FOR(i, H, B) {
        REP(j, A) {
            ans[i].push_back('0');
        }
        FOR(j, W, A) {
            ans[i].push_back('1');
        }
    }

    REP(i, H) {
        cout << ans[i] << endl;
    }
    return 0;
}