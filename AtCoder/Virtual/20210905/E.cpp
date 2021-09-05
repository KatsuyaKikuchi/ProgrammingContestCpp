#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

ll convert(string &s) {
    ll n = 0;
    REP(i, s.length()) {
        n = n * 10 + s[i] - '0';
    }
    return n;
}

bool check(string &s0, string &s1, string &s2) {
    if (s0[0] == '0' || s1[0] == '0' || s2[0] == '0')return false;
    ll a = convert(s0);
    ll b = convert(s1);
    ll c = convert(s2);
    return a + b == c;
}

void collect(string &s, vector<char> &v) {
    REP(i, s.length()) {
        if (s[i] >= 'a' && s[i] <= 'z')
            v.push_back(s[i]);
    }
}

void parse(string &s, vector<ll> &mp) {
    REP(i, s.length()) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = '0' + mp[s[i] - 'a'];
        }
    }
}

bool check(vector<char> &c, vector<ll> &v, string s0, string s1, string s2) {
    vector<ll> mp(30);
    REP(i, c.size()) {
        mp[c[i] - 'a'] = v[i];
    }
    parse(s0, mp);
    parse(s1, mp);
    parse(s2, mp);

    if (check(s0, s1, s2)) {
        cout << s0 << endl;
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
    }
    return false;
}

int main() {
    string S0, S1, S2;
    cin >> S0 >> S1 >> S2;

    vector<char> v;
    collect(S0, v);
    collect(S1, v);
    collect(S2, v);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() <= 10) {
        vector<ll> nums;
        REP(i, 10) {
            nums.push_back(i);
        }

        do {
            if (check(v, nums, S0, S1, S2)) {
                return 0;
            }
        } while (next_permutation(nums.begin(), nums.end()));
    }

    cout << "UNSOLVABLE" << endl;
    return 0;
}