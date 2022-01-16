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
    ll N, L;
    cin >> N >> L;

    vector<string> ans;
    REP(i, N) {
        string a, b, c;
        ll n = i;
        REP(j, L - 1) {
            ll x = n % 3;
            a.push_back('0' + x);
            b.push_back('0' + (2 + x) % 3);
            c.push_back('0' + (1 + x) % 3);
            n /= 3;
        }
        a.push_back('2');
        b.push_back('0');
        c.push_back('1');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
    }
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}