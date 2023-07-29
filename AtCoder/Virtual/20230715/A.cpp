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
    ll N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    std::set<pll> st;
    REP(_, M) {
        ll x, y;
        cin >> x >> y;
        st.insert(pll(x, y));
    }

    pll g(0, 0);
    bool e = true;
    REP(i, N) {
        H--;
        if (H < 0) {
            e = false;
            break;
        }

        if (S[i] == 'R') {
            g.first++;
        } else if (S[i] == 'L') {
            g.first--;
        } else if (S[i] == 'U') {
            g.second++;
        } else {
            g.second--;
        }

        if (st.find(g) != st.end() && H < K) {
            st.erase(g);
            H = std::max(H, K);
        }
    }

    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}