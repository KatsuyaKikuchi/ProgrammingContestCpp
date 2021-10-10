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
    vector<pll> A(N);
    vector<ll> v;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        v.push_back(A[i].first);
        v.push_back(A[i].first + A[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll> C(v.size(), 0);
    REP(i, N) {
        ll s = A[i].first;
        ll e = A[i].second + A[i].first;
        ll si = lower_bound(v.begin(), v.end(), s) - v.begin();
        ll ei = lower_bound(v.begin(), v.end(), e) - v.begin();
        C[si]++;
        C[ei]--;
    }

    REP(i, C.size() - 1) {
        C[i + 1] += C[i];
    }

#if false
    REP(i, C.size()) {
        cout << v[i] << "," << C[i] << endl;
    }
#endif

    vector<ll> ans(N + 5, 0);
    REP(i, C.size() - 1) {
        ll c = C[i];
        ll d = v[i + 1] - v[i];
        ans[c] += d;
    }
    REP(i, N) {
        cout << ans[i + 1] << " ";
    }
    cout << endl;
    return 0;
}