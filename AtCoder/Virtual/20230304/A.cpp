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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    deque<char> q;
    ll s = 0;
    REP(i, N) {
        if (S[i] == '(')s++;
        else s--;
        q.push_back(S[i]);
        if (s < 0) {
            q.push_front('(');
            s++;
        }
    }
    while (s > 0) {
        q.push_back(')');
        s--;
    }

    while (!q.empty()) {
        char t = q.front();
        q.pop_front();
        cout << t;
    }
    cout << endl;
    return 0;
}