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
    string pre;
    vector<string> suf;
    REP(i, N) {
        if (S[i] == 'd') {
            pre.push_back('d');
            continue;
        }
        FOR(j, N, i) {
            string s;
            FOR(n, j + 1, i) {
                char c = S[j - (n - i)];
                if (c == 'd')
                    s.push_back('p');
                if (c == 'p')
                    s.push_back('d');
            }
            FOR(n, N, j + 1) {
                s.push_back(S[n]);
            }
            suf.push_back(s);
        }
        break;
    }

    sort(suf.begin(), suf.end());
    cout << pre;
    if (!suf.empty())
        cout << suf[0];
    cout << endl;
    return 0;
}