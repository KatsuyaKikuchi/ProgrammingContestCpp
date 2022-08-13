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
    ll R, C;
    cin >> R >> C;
    vector<string> S(15);
    REP(i, 8) {
        string s;
        REP(j, 15) {
            if (j >= i && j <= 14 - i) {
                if (i % 2 == 0)s.push_back('B');
                else s.push_back('W');
            } else {
                if (j % 2 == 0)s.push_back('B');
                else s.push_back('W');
            }
        }
        S[i] = s;
    }
    REP(i, 8) {
        string s;
        REP(j, 15) {
            if (j >= i && j <= 14 - i) {
                if (i % 2 == 0)s.push_back('B');
                else s.push_back('W');
            } else {
                if (j % 2 == 0)s.push_back('B');
                else s.push_back('W');
            }
        }
        S[14 - i] = s;
    }


    if (S[R - 1][C - 1] == 'B')
        cout << "black" << endl;
    else
        cout << "white" << endl;
    return 0;
}