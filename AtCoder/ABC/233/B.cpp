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
    ll L, R;
    cin >> L >> R;
    string S;
    cin >> S;
    string a, b, c;
    L--;

    REP(i, L) {
        a.push_back(S[i]);
    }
    FOR(i, R, L) {
        b.push_back(S[i]);
    }
    FOR(i, S.length(), R) {
        c.push_back(S[i]);
    }
    reverse(b.begin(), b.end());
    cout << a << b << c << endl;
    return 0;
}