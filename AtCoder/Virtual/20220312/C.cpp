#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<char, char>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

bool check(const string &s, const vector<pll> &v, ll x) {
    char c = s[x];
    REP(i, v.size()) {
        if (v[i].first != c)
            continue;
        if (v[i].second == 'L')
            x--;
        else
            x++;
        if (x < 0)
            return true;
        if (x < s.length())
            c = s[x];
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pll> v(Q);
    REP(i, Q) {
        cin >> v[i].first >> v[i].second;
    }

    ll left = -1;
    {
        ll ng = N;
        while (abs(left - ng) > 1) {
            ll mid = (left + ng) / 2;
            if (check(S, v, mid))
                left = mid;
            else
                ng = mid;
        }
    }
    reverse(S.begin(), S.end());
    REP(i, Q) {
        if (v[i].second == 'L')
            v[i].second = 'R';
        else
            v[i].second = 'L';
    }
    ll right = -1;
    {
        ll ng = N;
        while (abs(right - ng) > 1) {
            ll mid = (right + ng) / 2;
            if (check(S, v, mid))
                right = mid;
            else
                ng = mid;
        }
    }

    ll ans = std::max(0LL, N - (left + 1 + right + 1));
    cout << ans << endl;
    return 0;
}