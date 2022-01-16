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
    vector<ll> v;
    ll sum = 0;
    REP(i, S.length()) {
        sum += S[i] - '0';
        v.push_back(sum);
    }
    reverse(v.begin(), v.end());
    queue<ll> q;
    REP(i, v.size()) {
        q.push(v[i]);
    }
    string ans;
    ll s = 0;
    while (s > 0 || !q.empty()) {
        if (!q.empty()) {
            s += q.front();
            q.pop();
        }
        ll c = s % 10;
        ans.push_back(c + '0');
        s /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}