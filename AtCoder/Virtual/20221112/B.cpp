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
    vector<ll> A(N), B(N), C(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    REP(i, N) {
        cin >> C[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll ans = 0;
    REP(i, N) {
        ll a = -1, c = N;
        {
            ll ng = N;
            while (abs(a - ng) > 1) {
                ll mid = (a + ng) / 2;
                if (A[mid] < B[i])a = mid;
                else ng = mid;
            }
        }
        {
            ll ng = -1;
            while (abs(c - ng) > 1) {
                ll mid = (c + ng) / 2;
                if (C[mid] > B[i])c = mid;
                else ng = mid;
            }
        }
        ans += (a + 1) * (N - c);
    }
    cout << ans << endl;
    return 0;
}