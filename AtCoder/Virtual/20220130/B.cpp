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
    std::multiset<ll> st;
    st.insert(INF);
    REP(i, N) {
        auto it = st.upper_bound(-A[i]);
        if (*it != INF) {
            st.erase(it);
        }
        st.insert(-A[i]);
    }
    cout << st.size() - 1 << endl;
    return 0;
}