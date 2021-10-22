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
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    REP(i, 2 * N) {
        cin >> A[i];
        A[i]--;
    }
    vector<ll> C(2 * N, 0);
    vector<ll> P(N, -1);
    REP(i, A.size()) {
        if (P[A[i]] < 0) {
            P[A[i]] = i;
            continue;
        }

        ll t = i - P[A[i]] - 1;
        C[t]++;
    }

    ll s = 0;
    REP(i, 2 * N - 1) {
        s += C[i];
        cout << s << endl;
    }
    return 0;
}