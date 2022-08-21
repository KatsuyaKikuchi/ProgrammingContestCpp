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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first;
    }

    ll ans = 0;
    ll p = pow(2, 35);
    while (p > 0) {
        sort(A.begin(), A.end(), greater<pll>());
        vector<pll> v(N);
        REP(i, N) {
            if ((A[i].first & p) > 0) {
                v[i].first = (A[i].first - p);
                v[i].second = A[i].second;
            } else {
                ll count = p - A[i].first;
                v[i].first = 0;
                v[i].second = A[i].second + count;
            }
        }
        sort(v.begin(), v.end(), [](pll a, pll b) { return a.second < b.second; });
        ll sum = 0;
        REP(i, K) {
            sum += v[i].second;
        }
        if (sum <= M) {
            ans |= p;
            swap(A, v);
        } else {
            REP(i, N) {
                if (A[i].first >= p)
                    A[i].first -= p;
            }
        }

        p >>= 1;
    }

    cout << ans << endl;

    return 0;
}