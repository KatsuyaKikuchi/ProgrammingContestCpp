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

string getNext(char c) {
    if (c == 'A')
        return "BC";
    if (c == 'B')
        return "CA";
    return "AB";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t, k;
        cin >> t >> k;
        k--;
        vector<ll> v;
        while (k > 0 && t > 0) {
            v.push_back(k % 2);
            t--;
            k = k / 2;
        }

        reverse(v.begin(), v.end());
        char c = (((S[k] - 'A') + t) % 3) + 'A';
        REP(i, v.size()) {
            string nxt = getNext(c);
            c = nxt[v[i]];
        }
        cout << c << endl;
    }
    return 0;
}