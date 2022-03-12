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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    stack<pll> s;
    ll count = 0;
    REP(i, N) {
        count++;
        ll a = A[i];
        if (s.empty()) {
            s.push(pll(a, 1));
        } else {
            pll t = s.top();
            if (t.first != a) {
                s.push(pll(a, 1));
            } else {
                s.pop();
                t.second++;
                if (t.first == t.second) {
                    count -= t.first;
                } else {
                    s.push(t);
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}