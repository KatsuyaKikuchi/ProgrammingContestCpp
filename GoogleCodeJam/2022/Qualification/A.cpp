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

void solve() {
    ll R, C;
    cin >> R >> C;
    vector<string> ans;
    REP(_, R) {
        string s0, s1;
        REP(__, C) {
            s0 += "+-";
            s1 += "|.";
        }
        s0.push_back('+');
        s1.push_back('|');
        ans.push_back(s0);
        ans.push_back(s1);
    }
    string s;
    REP(__, C) {
        s += "+-";
    }
    s.push_back('+');
    ans.push_back(s);
    ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = '.';

    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << endl;
        solve();
    }
    return 0;
}