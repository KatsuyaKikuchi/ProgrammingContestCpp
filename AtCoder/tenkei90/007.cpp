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

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    A.push_back(-INF);
    A.push_back(INF);
    sort(A.begin(), A.end());
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll b;
        cin >> b;
        ll index = lower_bound(A.begin(), A.end(), b) - A.begin();
        cout << std::min(abs(A[index - 1] - b), abs(A[index] - b)) << endl;
    }

    return 0;
}