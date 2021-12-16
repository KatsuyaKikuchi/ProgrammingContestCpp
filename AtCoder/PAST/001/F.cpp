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

string convert(string s) {
    s.front() += 'a' - 'A';
    s.back() += 'a' - 'A';
    return s;
}

string restore(string s) {
    s.front() += 'A' - 'a';
    s.back() += 'A' - 'a';
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    vector<string> v;
    string s;
    REP(i, N) {
        s.push_back(S[i]);
        if (S[i] >= 'A' && S[i] <= 'Z') {
            if (s.length() > 1) {
                v.push_back(convert(s));
                s.clear();
            }
        }
    }

    sort(v.begin(), v.end());
    REP(i, v.size()) {
        cout << restore(v[i]);
    }
    cout << endl;
    return 0;
}