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
    stack<char> s;
    REP(i, S.length()) {
        if (s.empty()) {
            s.push(S[i]);
            continue;
        }
        if (s.top() != S[i] && S[i] == 'T')
            s.pop();
        else
            s.push(S[i]);
    }
    cout << s.size() << endl;
    return 0;
}