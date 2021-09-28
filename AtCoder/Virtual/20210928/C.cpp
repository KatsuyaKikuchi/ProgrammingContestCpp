#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
vector<ll> A;
vector<ll> F;

bool check(ll x) {
    ll k = 0;
    REP(i, N) {
        ll t = A[i] * F[i];
        if (t <= x)
            continue;
        ll ok = A[i], ng = 0;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if ((A[i] - mid) * F[i] <= x)ok = mid;
            else ng = mid;
        }
        k += ok;
    }
    return k <= K;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    F.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> F[i];
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());
    ll ans = INF, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}