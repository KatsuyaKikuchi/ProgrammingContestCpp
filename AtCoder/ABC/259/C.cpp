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

struct Data {
    char c;
    ll count;
};

vector<Data> parse(string S) {
    ll n = 0;
    vector<Data> v;
    while (n < S.length()) {
        Data d{};
        d.c = S[n];
        d.count = 1;
        while (n + 1 < S.length()) {
            if (d.c != S[n + 1])
                break;
            d.count++;
            n++;
        }
        v.push_back(d);
        n++;
    }
    return v;
}

bool solve(string S, string T) {
    if (S.length() > T.length()) {
        return false;
    }
#if false
    ll N = S.length();
    ll M = T.length();
    ll n = 0, m = 0;
    while (n < N) {
        if (m >= M)
            return false;
        char cs = S[n];
        char ct = T[m];
        if (cs != ct)
            return false;
        ll c0 = 1, c1 = 1;
        while (n + 1 < N) {
            if (S[n + 1] != cs)
                break;
            c0++;
            n++;
        }
        while (m + 1 < M) {
            if (T[m + 1] != ct)
                break;
            c1++;
            m++;
        }

        if (c0 == 1 && c1 > c0)
            return false;
        if (c0 > c1)
            return false;
        n++;
        m++;
    }
    return true;
#else
    auto s = parse(S);
    auto t = parse(T);

    if (s.size() != t.size())
        return false;
    REP(i, s.size()) {
        if (s[i].c != t[i].c)
            return false;
        ll sc = s[i].count;
        ll tc = t[i].count;
        if (tc >= sc && sc >= 2)
            continue;
        if (tc == sc)
            continue;
        return false;
    }
    return true;
#endif
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    if (solve(S, T))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}