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

bool solve() {
    ll N;
    cin >> N;
    vector<pll> v(N);
    REP(i, N) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pll a, pll b) {
        return a.second < b.second;
    });
    std::set<pll> st;
    st.insert(pll(INF, INF));
    st.insert(pll(1, 1));
    REP(i, N) {
        pll r = v[i];
        auto it = st.lower_bound(pll(r.first, r.first));
        if (it->first > r.first)
            it--;
        if (it->second < r.first) {
            st.insert(pll(r.first, r.first + 1));
            it = st.find(pll(r.first, r.first + 1));
        } else if (it->second > r.second) {
            return false;
        } else {
            pll t = pll(it->first, it->second + 1);
            st.erase(it);
            st.insert(t);
            it = st.find(t);
        }

        while (true) {
            auto it2 = st.lower_bound(pll(it->second, it->second));
            if (it2->first != it->second) {
                break;
            }
            pll t = pll(it->first, it2->second);
            st.erase(it);
            st.erase(it2);
            st.insert(t);
            it = st.find(t);
        }

    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}