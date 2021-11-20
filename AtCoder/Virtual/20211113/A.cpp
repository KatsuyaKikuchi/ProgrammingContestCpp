#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

ll solve(string S, char c) {
    ll ret = 0;
    while (true) {
        bool fin = true;
        REP(i, S.size()) {
            if (S[i] != c) {
                fin = false;
                break;
            }
        }
        if (fin)break;
        ret++;
        string s = "";
        REP(i, S.size() - 1) {
            if (S[i] == c || S[i + 1] == c)
                s.push_back(c);
            else
                s.push_back(S[i]);
        }
        S = s;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll ans = INF;
    for (char c = 'a'; c <= 'z'; ++c) {
        string s = S;
        ans = std::min(ans, solve(s, c));
    }
    cout << ans << endl;
    return 0;
}