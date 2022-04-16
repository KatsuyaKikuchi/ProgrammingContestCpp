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
    vector<ll> v;
    REP(i, N) {
        vector<ll> tmp;
        for (auto t: v) {
            tmp.push_back(t);
        }
        tmp.push_back(i + 1);
        for (auto t: v) {
            tmp.push_back(t);
        }
        swap(tmp, v);
    }
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}