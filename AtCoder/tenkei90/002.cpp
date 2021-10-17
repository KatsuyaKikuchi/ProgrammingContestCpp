#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;

string build(ll bit) {
    string ret = "";
    REP(i, N) {
        if ((bit >> i) & 1)
            ret.push_back('(');
        else
            ret.push_back(')');
    }
    return ret;
}

bool check(string &s) {
    ll d = 0;
    REP(i, N) {
        if (s[i] == '(')
            d++;
        else
            d--;
        if (d < 0)
            return false;
    }
    return d == 0;
}

int main() {
    cin >> N;
    vector<string> ans;
    REP(bit, pow(2LL, N)) {
        string s = build(bit);
        if (check(s))
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}