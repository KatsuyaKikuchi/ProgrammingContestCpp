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

ll N, A, B, C;

ll solve(const vector<ll> &L) {
    ll ret = INF;
    ll n = L.size();
    REP(i, n) {
        REP(j, n) {
            if (i == j)
                continue;
            REP(k, n) {
                if (i == k || j == k)
                    continue;
                ret = std::min(ret, abs(L[i] - A) + abs(L[j] - B) + abs(L[k] - C));
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C;
    vector<ll> L(N);
    REP(i, N) {
        cin >> L[i];
    }

    ll ans = INF;
    REP(bit, pow(4, N)) {
        vector<ll> c[4];
        ll b = bit;
        REP(i, N) {
            c[b % 4].push_back(L[i]);
            b /= 4;
        }
        vector<ll> v;
        ll sum = 0;
        FOR(i, 4, 1) {
            if (c[i].size() == 0)
                continue;
            sum += 10 * (c[i].size() - 1);
            ll len = 0;
            REP(j, c[i].size()) {
                len += c[i][j];
            }
            v.push_back(len);
        }
        REP(i, c[0].size()) {
            v.push_back(c[0][i]);
        }

        ans = std::min(ans, solve(v) + sum);
    }
    cout << ans << endl;
    return 0;
}