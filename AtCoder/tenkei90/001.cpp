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

ll N, L, K;
vector<ll> A;

bool check(ll m) {
    ll num = 0;
    ll s = 0;
    REP(i, A.size() - 1) {
        s += A[i + 1] - A[i];
        if (s >= m) {
            num++;
            s = 0;
        }
    }
    return num >= K + 1;
}

int main() {

    cin >> N >> L >> K;
    A.resize(0);
    A.push_back(0);
    A.push_back(L);
    REP(i, N) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    ll ans = 1, ng = L + 1;
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