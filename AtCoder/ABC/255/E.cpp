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
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N - 1);
    REP(i, S.size()) {
        cin >> S[i];
    }
    vector<ll> X(M);
    REP(i, M) {
        cin >> X[i];
    }
    vector<ll> A(N);
    A[0] = 0;
    std::map<ll, ll> odd, even;
    even[0]++;
    FOR(i, N, 1) {
        A[i] = S[i - 1] - A[i - 1];
        if (i % 2 == 0)
            even[A[i]]++;
        else
            odd[A[i]]++;
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, M) {
            ll d = X[j] - A[i];
            ll count = 0;
            REP(k, M) {
                if (i % 2 == 0) {
                    if (even.find(X[k] - d) != even.end())
                        count += even[X[k] - d];
                    if (odd.find(X[k] + d) != odd.end())
                        count += odd[X[k] + d];
                } else {
                    if (even.find(X[k] + d) != even.end())
                        count += even[X[k] + d];
                    if (odd.find(X[k] - d) != odd.end())
                        count += odd[X[k] - d];
                }
            }

            ans = std::max(count, ans);
        }
    }

    cout << ans << endl;
    return 0;
}