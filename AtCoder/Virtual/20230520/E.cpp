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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    std::map<ll, ll> mp;
    REP(i, N) {
        A[i] = i;
        mp[i] = i;
    }

    REP(_, Q) {
        ll x;
        cin >> x;
        ll index = mp[x - 1];
        ll ni = (index + 1);
        if (ni >= N)
            ni = N - 2;
        swap(A[index], A[ni]);
        mp[A[index]] = index;
        mp[A[ni]] = ni;
    }

    REP(i, N) {
        cout << A[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}