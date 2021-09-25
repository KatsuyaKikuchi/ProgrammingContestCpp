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

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> V(M);
    REP(i, M) {
        ll k;
        cin >> k;
        REP(j, k) {
            ll a;
            cin >> a;
            a--;
            V[i].push_back(a);
        }
    }
    vector<ll> idx(M, 0);
    vector<ll> C(N, -1);
    queue<ll> q;
    REP(i, M) {
        q.push(i);
    }

    ll count = 0;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll c = V[t][idx[t]];
        if (C[c] < 0) {
            C[c] = t;
            continue;
        }

        ll x = C[c];
        idx[x]++;
        if (V[x].size() > idx[x]) {
            q.push(x);
        }
        idx[t]++;
        if (V[t].size() > idx[t]) {
            q.push(t);
        }
        count++;
    }

    if (count == N)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}