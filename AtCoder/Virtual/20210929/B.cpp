#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <map>

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
    vector<ll> O;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        if (i % 2 == 0)
            O.push_back(A[i]);
    }
    sort(O.begin(), O.end());
    sort(A.begin(), A.end());
    std::map<ll, ll> mp;
    REP(i, N) {
        mp[A[i]] = i % 2;
    }
    ll ans = 0;
    REP(i, O.size()) {
        if (mp[O[i]] == 1)ans++;
    }
    cout << ans << endl;
    return 0;
}