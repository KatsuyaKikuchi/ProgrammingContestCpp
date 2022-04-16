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

bool same(pll a0, pll a1, pll b0, pll b1) {
    ll x0 = a0.first - a1.first;
    ll y0 = a0.second - a1.second;

    ll x1 = b0.first - b1.first;
    ll y1 = b0.second - b1.second;
    return x0 * y1 == x1 * y0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            ll count = 0;
            if (A[i].first == A[j].first) {
                REP(k, N) {
                    if (A[k].first != A[i].first)
                        continue;
                    count++;
                    if (i != k && j != k && k < j) {
                        count = -1;
                        break;
                    }
                }
            } else {
                REP(k, N) {
                    if (!same(A[i], A[j], A[i], A[k]))
                        continue;
                    count++;
                    if (i != k && j != k && k < j) {
                        count = -1;
                        break;
                    }
                }
            }
            if (count >= K)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}