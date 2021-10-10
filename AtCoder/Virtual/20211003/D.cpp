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

vector<string> S;
char C[3] = {'3', '5', '7'};

void dfs(string s) {
    if (s.length() >= 10)
        return;
    REP(i, 3) {
        s.push_back(C[i]);
        S.push_back(s);
        dfs(s);
        s.pop_back();
    }
}

ll toInt(string &s) {
    ll ret = 0;
    REP(i, s.length()) {
        ret = ret * 10LL + s[i] - '0';
    }
    return ret;
}

bool check(ll n) {
    vector<ll> v(3, 0);
    while (n > 0) {
        ll m = n % 10;
        switch (m) {
            case 3:
                v[0]++;
                break;
            case 5:
                v[1]++;
                break;
            case 7:
                v[2]++;
                break;
        }
        n /= 10;
    }
    REP(i, 3) {
        if (v[i] == 0)
            return false;
    }
    return true;
}

int main() {
    ll N;
    cin >> N;

    dfs("");

    ll ans = 0;
    REP(i, S.size()) {
        ll n = toInt(S[i]);
        if (n > N)
            continue;
        if (check(n)) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}