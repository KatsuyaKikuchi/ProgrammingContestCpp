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
    string S, T;
    cin >> S >> T;

    ll N = S.length();
    ll k = (T[0] - S[0] + 26) % 26;
    REP(i, N) {
        S[i] = ((S[i] - 'a' + k) % 26 + 'a');
    }

    if (S == T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}