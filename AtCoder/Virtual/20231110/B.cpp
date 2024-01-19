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
    deque<char> q;
    bool reverse = false;
    REP(i, S.size()) {
        if (S[i] == 'R') {
            reverse = !reverse;
            continue;
        }
        if (reverse) {
            q.push_front(S[i]);
        } else {
            q.push_back(S[i]);
        }
    }

    string ans = "";
    while (!q.empty()) {
        char c;
        if (reverse) {
            c = q.back();
            q.pop_back();
        } else {
            c = q.front();
            q.pop_front();
        }
        if (ans.back() == c) {
            ans.pop_back();
        } else {
            ans.push_back(c);
        }
    }
    cout << ans << endl;
    return 0;
}