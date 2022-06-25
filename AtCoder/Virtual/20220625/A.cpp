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
    ll L, Q;
    cin >> L >> Q;
    std::set<ll> st;
    st.insert(0);
    st.insert(L);
    REP(i, Q) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto it = st.lower_bound(x);
            ll ret = *it;
            it--;
            ret -= *it;
            cout << ret << endl;
        }
    }
    return 0;
}