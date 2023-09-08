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
    deque<char> s;
    ll count = 0;
    REP(i, N) {
        if (S[i] == ')' && count > 0) {
            while (s.back() != '(') {
                s.pop_back();
            }
            s.pop_back();
            count--;
            continue;
        } else if (S[i] == '(') {
            count++;
        }
        s.push_back(S[i]);
    }

    while (!s.empty()) {
        cout << s.front();
        s.pop_front();
    }
    cout << endl;
    return 0;
}