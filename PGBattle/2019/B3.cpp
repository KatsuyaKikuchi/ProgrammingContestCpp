#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<ll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N + 1);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        V[b].node.push_back(a);
    }
    vector<ll> C(N + 1, INF);
    C[0] = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (C[t.first] < t.second)
            continue;
        for (auto &n: V[t.first].node) {
            ll c = t.second + 1;
            if (C[n] <= c)
                continue;
            C[n] = c;
            q.push(pll(n, c));
        }
    }

    REP(i, N) {
        if (C[i + 1] <= 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}