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
    vector<ll> v;
    v.push_back(-1);
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    v.push_back(INF);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<vector<ll>> nums(v.size());
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        nums[index].push_back(i);
    }

    REP(_, Q) {
        ll x, k;
        cin >> x >> k;
        ll index = lower_bound(v.begin(), v.end(), x) - v.begin();
        if (v[index] != x || nums[index].size() < k) {
            cout << -1 << endl;
            continue;
        }
        cout << nums[index][k - 1] + 1 << endl;
    }
    return 0;
}