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

string A[3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    vector<bitset<3005>> bit;
    REP(i, N) {
        bit.emplace_back(0);
    }

    REP(j, N) {
        REP(i, j) {
            if (A[i][j] == '1')
                bit[j].set(i);
        }
    }

    REP(k, N) {
        REP(j, k) {
            if (A[j][k] == '1') {
                bitset b = (bit[k] & bit[j]);
                ll count = b.count();
                ans += count;
            }
        }
    }
    cout << ans << endl;
    return 0;
}