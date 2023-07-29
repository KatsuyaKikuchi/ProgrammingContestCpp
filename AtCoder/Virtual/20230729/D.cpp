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
    string S;
    cin >> S;
    vector<ll> C(2, 0);
    ll ans = 0;
    REP(i, N) {
        vector<ll> tmp(2, 0);
        if (S[i] == '0') {
            tmp[0]++;
            tmp[1] += C[0] + C[1];
        } else {
            tmp[1]++;
            tmp[1] += C[0];
            tmp[0] += C[1];
        }
        swap(C, tmp);
        ans += C[1];
    }
    cout << ans << endl;
    return 0;
}