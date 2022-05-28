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
    std::map<ll, ll> index;
    REP(i, N) {
        cin >> A[i];
        index[A[i] - 1] = i;
    }

    std::set<ll> st;
    st.insert(N);
    st.insert(-1);
    ll ans = 0;
    REP(i, N) {
        ll idx = index[i];
        auto it = st.lower_bound(idx);
        ll w = (*it) - idx;
        it--;
        ll h = idx - (*it);
        ans += w * h * (i + 1);
        st.insert(idx);
    }
    cout << ans << endl;

    return 0;
}