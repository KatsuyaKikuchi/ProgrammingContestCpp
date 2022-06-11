#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e8;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K);
    REP(i, K) {
        cin >> A[i];
    }

    vector<pll> B(N);
    REP(i, N) {
        cin >> B[i].first >> B[i].second;
    }

    double ans = INF, ng = -1;
    REP(_, 80) {
        vector<bool> u(N, false);
        double r = (ans + ng) * 0.5;
        ll count = 0;
        REP(i, K) {
            ll a = A[i] - 1;
            REP(j, N) {
                double len = sqrt(pow(B[a].first - B[j].first, 2.0) + pow(B[a].second - B[j].second, 2.0));
                if (len <= r)
                    u[j] = true;
            }
        }

        REP(i, N) {
            if (u[i])count++;
        }

        if (count == N)
            ans = r;
        else ng = r;
    }

    cout << OF64 << ans << endl;

    return 0;
}