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

std::map<string, ll> mp;
ll ans = INF;

void dfs(string &s, ll count = 0) {
    if (s == "atcoder") {
        ans = std::min(ans, count);
        return;
    }
    count++;
    if (ans <= count)
        return;
    REP(i, s.size() - 1) {
        swap(s[i], s[i + 1]);
        auto it = mp.find(s);
        if (it == mp.end() || it->second > count) {
            mp[s] = count;
            dfs(s, count);
        }
        swap(s[i], s[i + 1]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll count = 0;
    string s = "atcoder";
    REP(i, S.size()) {
        for (ll j = S.size(); j > i; --j) {
            if (S[j] == s[i]) {
                swap(S[j], S[j - 1]);
                count++;
            }
        }
    }
    cout << count << endl;
    //dfs(S);
    //cout << ans << endl;
    return 0;
}