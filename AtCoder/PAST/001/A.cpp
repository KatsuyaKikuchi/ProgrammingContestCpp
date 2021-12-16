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
    string S;
    cin >> S;
    ll n = 0;
    REP(i, S.length()) {
        if (S[i] >= '0' && S[i] <= '9') {
            n = n * 10 + S[i] - '0';
        } else {
            n = -1;
            break;
        }
    }

    if (n < 0)
        cout << "error" << endl;
    else
        cout << n * 2 << endl;
    return 0;
}