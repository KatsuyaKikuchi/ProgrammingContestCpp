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
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    string S;

    while (N != 0) {
        if (N < 0) {
            S.push_back('0' + (-N) % 2);
            N = (-N + 1) / 2;
        } else {
            S.push_back('0' + N % 2);
            N = -(N / 2);
        }
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
    return 0;
}