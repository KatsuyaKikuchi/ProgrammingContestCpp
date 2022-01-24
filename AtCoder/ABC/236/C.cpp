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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    std::set<string> st;
    REP(_, M) {
        string s;
        cin >> s;
        st.insert(s);
    }

    REP(i, N) {
        if (st.find(S[i]) != st.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}