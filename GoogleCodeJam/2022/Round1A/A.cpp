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

string solve() {
    string S;
    cin >> S;
    string ret = "";
    ll N = S.length();
    ll count = 0;
    REP(i, N - 1) {
        ret.push_back(S[i]);
        count++;
        if (S[i] < S[i + 1]) {
            REP(_, count) {
                ret.push_back(S[i]);
            }
            count = 0;
        } else if (S[i] == S[i + 1]) {
        } else {
            count = 0;
        }
    }
    ret.push_back(S[N - 1]);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}