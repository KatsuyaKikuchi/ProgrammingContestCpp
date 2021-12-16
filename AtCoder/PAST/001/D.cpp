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
    vector<ll> A(N, 0);
    REP(i, N) {
        ll a;
        cin >> a;
        A[a - 1]++;
    }
    pll ans(-1, -1);
    REP(i, N) {
        if (A[i] == 0)
            ans.first = i + 1;
        if (A[i] > 1)
            ans.second = i + 1;
    }

    if (ans.first == -1)
        cout << "Correct" << endl;
    else
        cout << ans.second << " " << ans.first << endl;
    return 0;
}