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
    ll N;
    cin >> N;
    std::map<string, ll> mp;
    bool e = true;
    vector<string> S, T;
    REP(i, N) {
        string s, t;
        cin >> s >> t;
        mp[s]++;
        mp[t]++;
        S.push_back(s);
        T.push_back(t);
    }

    REP(i, N) {
        mp[S[i]]--;
        mp[T[i]]--;

        if (mp[S[i]] > 0 && mp[T[i]] > 0)e = false;
        mp[S[i]]++;
        mp[T[i]]++;
    }

    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}