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

ll N;
vector<ll> A;

ll check(ll m) {
    ll x = -1, ng = N;
    while (abs(ng - x) > 1) {
        ll mid = (x + ng) / 2;
        if (A[mid] > 0 && A[mid] >= m)
            x = mid;
        else
            ng = mid;
    }
    return x + 1;
}

ll solve(ll n) {
    ll ret = A[0] + 1, ng = -1;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        if (check(mid) <= n)
            ret = mid;
        else
            ng = mid;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll q;
        cin >> q;
        cout << solve(q) << endl;
    }

    return 0;
}