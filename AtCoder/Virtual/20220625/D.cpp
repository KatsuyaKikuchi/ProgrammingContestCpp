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
    string S;
    cin >> S;
    vector<ll> counts;
    vector<char> s;
    counts.push_back(0);
    REP(i, N) {
        if (S[i] == 'C') {
            ll n = s.size();
            if (n >= 2 && s[n - 1] == 'R' && s[n - 2] == 'A') {
                counts.back()++;
                s.pop_back();
                s.pop_back();
                s.push_back('R');
            } else {
                s.push_back(S[i]);
            }
        } else {
            s.push_back(S[i]);
            if (counts.back() != 0) {
                counts.push_back(0);
            }
        }
    }

    ll count = 0;
    vector<ll> v;
    REP(i, counts.size()) {
        if (counts[i] == 0)
            continue;
        else {
            count += counts[i];
            v.push_back(counts[i]);
        }
    }
    cout << std::min(count, (ll) v.size() * 2) << endl;

    return 0;
}