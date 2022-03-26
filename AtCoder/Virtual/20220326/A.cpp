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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    std::map<ll, ll> mp;
    mp[1] = N + 10;
    REP(i, N) {
        auto it = mp.upper_bound(-A[i]);
        it->second--;
        if (it->second == 0) {
            mp.erase(it);
        }
        mp[-A[i]]++;
    }

    ll ans = 0;
    for (auto v: mp) {
        if (v.first > 0)
            continue;
        ans += v.second;
    }
    cout << ans << endl;

    return 0;
}