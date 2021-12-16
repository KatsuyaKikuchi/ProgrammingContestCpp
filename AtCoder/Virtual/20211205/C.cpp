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
    vector<pll> node;
    ll Value;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, N) {
        cin >> V[i].Value;
    }
    REP(_, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }

    vector<ll> C(N, INF);
    vector<ll> A(N, 0);
    A[0] = V[0].Value;
    C[0] = 0;
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(0, 0));
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (C[t.first] < t.second)
                continue;
            for (auto &n: V[t.first].node) {
                ll cost = n.second + t.second;
                if (C[n.first] < cost)
                    continue;

                if (C[n.first] == cost) {
                    A[n.first] = std::max(A[n.first], A[t.first] + V[n.first].Value);
                    continue;
                }
                A[n.first] = A[t.first] + V[n.first].Value;
                C[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }

    cout << A[N - 1] << endl;

    return 0;
}