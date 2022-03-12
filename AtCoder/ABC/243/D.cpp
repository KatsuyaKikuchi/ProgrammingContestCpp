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
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    stack<char> s;
    REP(i, N) {
        if (s.empty()) {
            s.push(S[i]);
            continue;
        }

        if (S[i] == 'U' && (s.top() == 'L' || s.top() == 'R')) {
            s.pop();
            continue;
        }
        s.push(S[i]);
    }

    string v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());
    N = v.length();
    REP(i, N) {
        if (v[i] == 'U')
            X /= 2;
        else if (v[i] == 'L')
            X = 2LL * X;
        else
            X = 2LL * X + 1;
    }
    cout << X << endl;
    return 0;
}