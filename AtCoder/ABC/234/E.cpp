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

ll toint(string s) {
    ll ret = 0;
    REP(i, s.size()) {
        ret = ret * 10LL + s[i] - '0';
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X;
    cin >> X;
    if (X <= 99) {
        cout << X << endl;
        return 0;
    }
    ll mx = 0;
    while (mx <= X) {
        mx = mx * 10LL + 1;
    }
    string s;
    ll x = X;
    while (x > 0) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    for (ll i = s.size() - 1; i > 0; --i) {
        ll t = (s[1] - '0') - (s[0] - '0');
        bool ok = true;
        FOR(j, i + 1, 1) {
            ll tt = (s[j] - '0') - (s[j - 1] - '0');
            if (tt == t)
                continue;
            ok = false;
            break;
        }
        if (!ok)
            continue;
        string ans;
        REP(j, i + 1) {
            ans.push_back(s[j]);
        }
        FOR(j, s.size(), i + 1) {
            ll nx = t + ans.back() - '0';
            if (nx < 0 || nx >= 10) {
                ok = false;
                break;
            }
            ans.push_back(nx + '0');
        }

        ok &= (X <= toint(ans));

        if (!ok)
            continue;
        cout << ans << endl;
        return 0;
    }

    for (ll start = s[0] - '0'; start <= 9; ++start) {
        for (ll d = -10; d <= 10; d++) {
            ll n = start;
            string ans;
            ans.push_back(n + '0');
            bool ok = true;
            while (ans.size() < s.size()) {
                ll nx = ans.back() - '0' + d;
                if (nx < 0 || nx >= 10) {
                    ok = false;
                    break;
                }
                ans.push_back(nx + '0');
            }

            ok &= (X <= toint(ans));
            if (!ok)
                continue;
            cout << ans << endl;
            return 0;
        }
    }

    cout << mx << endl;
    return 0;
}