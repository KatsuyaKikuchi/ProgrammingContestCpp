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

struct Data {
    ll prev = -1;
    ll count = 1;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }

    vector<ll> ans(N, -1);
    std::set<ll> st;
    vector<Data> D(N);
    REP(i, N) {
        auto it = st.lower_bound(P[i]);
        if (it == st.end()) {
            if (K == 1) {
                ans[P[i]] = i + 1;
            } else {
                st.insert(P[i]);
            }
            continue;
        }
        auto d = D[*it];
        D[P[i]].prev = *it;
        D[P[i]].count = d.count + 1;
        st.erase(it);
        st.insert(P[i]);
        ll n = P[i];
        if (D[n].count < K)
            continue;

        while (n >= 0) {
            ans[n] = i + 1;
            st.erase(n);
            n = D[n].prev;
        }
    }

    REP(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}