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
    ll M, K;
    cin >> M >> K;
    ll N = pow(2LL, M);
    if (N - 1 < M) {
        cout << -1 << endl;
        return 0;
    }
    if (K == 0) {
        REP(i, N) {
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }

    vector<pll> P;
    set<ll> st;
    REP(i, N) {
        st.insert(i);
        ll p = (K ^ i);
        if (st.find(p) != st.end()) {
            continue;
        }
        P.emplace_back(i, p);
        st.insert(p);
    }

    if (P.size() % 2 != 0 || P.size() * 2 != N) {
        cout << -1 << endl;
        return 0;
    }
    for (ll i = 0; i < P.size(); i += 2) {
        cout << P[i].first << " " << P[i].second << " ";
        cout << P[i + 1].first << " " << P[i + 1].second << " ";
        cout << P[i].second << " " << P[i].first << " ";
        cout << P[i + 1].second << " " << P[i + 1].first << " ";
    }
    cout << endl;
    return 0;
}