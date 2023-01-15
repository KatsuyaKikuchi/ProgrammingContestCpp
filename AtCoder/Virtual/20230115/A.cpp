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
    string S;
    cin >> S;
    ll ans = INF;
    for (char c = 'a'; c <= 'z'; ++c) {
        ll count = 0;
        string s = S;
        while (true) {
            bool e = true;
            REP(i, s.size()) {
                if (s[i] != c)
                    e = false;
            }
            if (e)
                break;

            string t = "";
            REP(i, s.size() - 1) {
                if (s[i] == c || s[i + 1] == c)
                    t.push_back(c);
                else
                    t.push_back(s[i]);
            }
            count++;
            s = t;
        }
        ans = std::min(count, ans);
    }
    cout << ans << endl;
    return 0;
}