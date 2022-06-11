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
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    ll s = A;
    ll e = A + D * (N - 1);

    ll ans = 0;
    if (s >= e) {
        if (s <= X) {
            ans = X - s;
        } else if (X <= e) {
            ans = e - X;
        } else {
            ll ok = N, ng = 0;
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                ll n = A + D * (mid - 1);
                if (n <= X)
                    ok = mid;
                else
                    ng = mid;
            }

            ll n0 = A + D * (ok - 1);
            ll n1 = A + D * std::max(0LL, ok - 2);
            ll n2 = A + D * std::min(ok, N - 1);
            ans = std::min({abs(X - n0), abs(X - n1), abs(X - n2)});
        }
    } else {
        if (X <= s) {
            ans = s - X;
        } else if (e <= X) {
            ans = X - e;
        } else {
            ll ok = 1, ng = N + 1;
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                ll n = A + D * (mid - 1);
                if (n <= X)
                    ok = mid;
                else
                    ng = mid;
            }

            ll n0 = A + D * (ok - 1);
            ll n1 = A + D * std::max(0LL, ok - 2);
            ll n2 = A + D * std::min(ok, N - 1);
            ans = std::min({abs(X - n0), abs(X - n1), abs(X - n2)});
        }
    }
    cout << ans << endl;
    return 0;
}