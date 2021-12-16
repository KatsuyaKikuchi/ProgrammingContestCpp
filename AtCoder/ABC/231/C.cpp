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
ll N, Q;
vector<ll> A;

ll solve(ll x) {
    ll ret = -1, ng = N;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        if (A[mid] >= x)
            ret = mid;
        else ng = mid;
    }
    return ret + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    REP(_, Q) {
        ll q;
        cin >> q;
        cout << solve(q) << endl;
    }
    return 0;
}