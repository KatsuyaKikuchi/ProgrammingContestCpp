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

string query(ll n) {
    string s;
    cout << n << endl;
    cin >> s;

    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string start = query(0);
    if (start == "Vacant") {
        return 0;
    }
    ll index = 0;
    ll ng = N;
    REP(_, 19) {
        ll nxt = (index + ng) / 2;
        string s = query(nxt);
        if (s == "Vacant") {
            break;
        }
        ll d = nxt - index;
        if (d % 2 == 0) {
            if (start == s) {
                start = s;
                index = nxt;
            } else {
                ng = nxt;
            }
        } else {
            if (start != s) {
                start = s;
                index = nxt;
            } else {
                ng = nxt;
            }
        }
    }
    return 0;
}