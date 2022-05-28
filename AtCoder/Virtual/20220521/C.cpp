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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);
    std::set<ll> sa, sb;
    REP(i, N) {
        sa.insert(i + 1);
        sb.insert(i + 1);
    }
    A[N - 1] = 1;
    sa.erase(1);
    B[N - 1] = N;
    sb.erase(N);
    ll x = N - 1;
    for (ll i = N - 2; i >= 0; --i) {
        {
            if (sa.find(x - A[i + 1]) != sa.end()) {
                A[i] = x - A[i + 1];
                sa.erase(x - A[i + 1]);
            } else {
                A[i] = -x + A[i + 1];
                sa.erase(-x + A[i + 1]);
            }
        }
        {
            if (sb.find(x - B[i + 1]) != sb.end()) {
                B[i] = x - B[i + 1];
                sb.erase(x - B[i + 1]);
            } else {
                B[i] = -x + B[i + 1];
                sb.erase(-x + B[i + 1]);
            }
        }
        x--;
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    REP(i, N) {
        cout << B[i] << " ";
    }
    return 0;
}