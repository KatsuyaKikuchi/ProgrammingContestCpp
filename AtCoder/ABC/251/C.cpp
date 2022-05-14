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
    ll s = -1;
    std::set<string> st;
    ll ans = -1;
    REP(i, N) {
        string S;
        ll T;
        cin >> S >> T;
        if (st.find(S) == st.end()) {
            if (s < T)
                ans = i + 1;
            s = std::max(T, s);
        }
        st.insert(S);
    }
    cout << ans << endl;
    return 0;
}