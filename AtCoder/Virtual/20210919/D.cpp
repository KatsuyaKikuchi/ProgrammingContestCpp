#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll Q;
    cin >> Q;
    multiset<ll> st;
    queue<ll> q;
    REP(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            q.push(x);
        } else if (t == 2) {
            ll out = -1;
            if (st.empty()) {
                out = q.front();
                q.pop();
            } else {
                auto it = st.begin();
                out = *it;
                st.erase(it);
            }
            cout << out << endl;
        } else {
            while (!q.empty()) {
                ll x = q.front();
                q.pop();
                st.insert(x);
            }
        }
    }
    return 0;
}