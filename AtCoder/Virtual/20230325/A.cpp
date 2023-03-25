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
    vector<string> T;
    T.push_back(S);
    ll s = N;
    REP(i, N) {
        if (S[i] == 'p') {
            s = i;
            break;
        }
    }
    for (ll i = N - 1; i > s; --i) {
        string t;
        REP(j, N) {
            t.push_back(S[j]);
        }
        ll x = 0;
        while ((s + x) <= (i - x)) {
            swap(t[s + x], t[i - x]);
            x++;
        }
        //cout << t << " ";
        FOR(j, i + 1, s) {
            if (t[j] == 'p')
                t[j] = 'd';
            else
                t[j] = 'p';
        }
        //cout << t << endl;
        T.push_back(t);
    }
    sort(T.begin(), T.end());

    cout << T[0];
    return 0;
}