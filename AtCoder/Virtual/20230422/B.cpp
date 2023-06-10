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

ll count(string &s) {
    ll ret = 0;
    REP(j, s.size() - 1) {
        if (s[j] == 'A' && s[j + 1] == 'B')
            ret++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<queue<string>> C(4);
    REP(i, N) {
        string s;
        cin >> s;
        ll index;
        if (s[0] == 'B') {
            if (s[s.size() - 1] == 'A') {
                index = 1;
            } else {
                index = 2;
            }
        } else if (s[s.size() - 1] == 'A') {
            index = 0;
        } else {
            index = 3;
        }
        C[index].push(s);
    }

    string S;
    while (true) {
        ll count = min(C[0].size(), C[2].size());
        if (count <= 1)
            break;
        string s0 = C[0].front();
        C[0].pop();
        string s1 = C[2].front();
        C[2].pop();
        C[3].push(s0 + s1);
    }
    REP(i, 4) {
        while (!C[i].empty()) {
            auto s = C[i].front();
            C[i].pop();
            S += s;
        }
    }

    //cout << S << endl;

    cout << count(S) << endl;
    return 0;
}