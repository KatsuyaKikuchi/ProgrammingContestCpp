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
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll ans = 1;
    vector<ll> cnt(v.size(), 0);
    ll val = 0;
    ll left = 0;
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        if (++cnt[index] == 1)
            val++;
        while (val > K) {
            ll pi = lower_bound(v.begin(), v.end(), A[left]) - v.begin();
            cnt[pi]--;
            left++;
            if (cnt[pi] == 0)
                val--;
        }
        ans = std::max(ans, i - left + 1);
    }
    cout << ans << endl;
    return 0;
}