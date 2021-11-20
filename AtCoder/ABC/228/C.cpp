#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> V(N);
    REP(i, N) {
        A[i] = 0;
        REP(j, 3) {
            ll p;
            cin >> p;
            A[i] += p;
        }
        V[i] = A[i];
    }
    sort(V.begin(), V.end());
    V.push_back(INF);
    REP(i, N) {
        ll s = A[i] + 300;
        ll index = upper_bound(V.begin(), V.end(), s) - V.begin();
        ll n = N - index + 1;
        if (n <= K)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}