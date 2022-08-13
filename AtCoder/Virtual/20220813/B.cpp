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
    vector<ll> v0(N, INF), v1(N, INF);
    REP(i, N - 2) {
        cout << "? 1 " << i + 3 << endl;
        cin >> v0[i + 2];
    }
    REP(i, N - 2) {
        cout << "? 2 " << i + 3 << endl;
        cin >> v1[i + 2];
    }

    vector<ll> v;
    REP(i, N) {
        if (v1[i] == 1)
            v.push_back(i);
    }

    if (v.size() == 0) {
        cout << "! 1" << endl;
        return 0;
    }
    vector<ll> t;
    REP(i, v.size()) {
        t.push_back(v0[v[i]]);
    }
    sort(t.begin(), t.end());

    ll ans = 1;
    if (t[0] != 2) {
        ans = t[0] + 1;
    } else {
        if (t.size() == 1) {
            vector<ll> x;
            REP(i, N) {
                if (v1[i] == 2)
                    x.push_back(i);
            }
            ll index = x[0];
            REP(i, x.size()) {
                if (v0[index] > v0[x[i]])
                    index = x[i];
            }
            ll value;
            cout << "? " << index + 1 << " " << v[0] + 1 << endl;
            cin >> value;
            if (value == 1 && v0[index] < v0[v[0]]) {
                ans = 3;
            } else {
                ans = 1;
            }
        } else if (t[1] == 2) {
            ans = 1;
        } else {
            ans = t[0] + 1;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}