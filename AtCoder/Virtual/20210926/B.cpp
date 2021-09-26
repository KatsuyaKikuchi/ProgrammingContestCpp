#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> p;
    ll n = 1;
    while (n * n <= M) {
        if (M % n == 0) {
            p.push_back(n);
            p.push_back(M / n);
        }
        n++;
    }
    sort(p.begin(), p.end(), greater<ll>());
    REP(i, p.size()) {
        ll t = M / p[i];
        if (t >= N) {
            cout << p[i] << endl;
            break;
        }
    }
    return 0;
}