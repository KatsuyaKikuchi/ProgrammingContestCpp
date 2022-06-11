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

struct Circle {
    double x, y, r;
};

struct Edge {
    ll to;
    double cost;
};
struct Vertex {
    vector<Edge> node;
};

double calcCost(Circle c0, Circle c1) {
    double len = sqrt(pow(c0.x - c1.x, 2) + pow(c0.y - c1.y, 2));
    return std::max(0.0, len - (c0.r + c1.r));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<Circle> C;
    {
        double x, y;
        cin >> x >> y;
        C.push_back(Circle{x, y, 0});
    }
    {
        double x, y;
        cin >> x >> y;
        C.push_back(Circle{x, y, 0});
    }
    ll N;
    cin >> N;
    REP(i, N) {
        double x, y, r;
        cin >> x >> y >> r;
        C.push_back(Circle{x, y, r});
    }

    N = C.size();
    vector<Vertex> V(N);
    REP(i, N) {
        FOR(j, N, i + 1) {
            double cost = calcCost(C[i], C[j]);
            V[i].node.push_back(Edge{j, cost});
            V[j].node.push_back(Edge{i, cost});
        }
    }

    vector<double> D(N, INF);
    D[0] = 0;

    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q([](Edge a, Edge b) { return a.cost > b.cost; });
    q.push(Edge{0, 0});
    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        if (D[e.to] < e.cost)
            continue;
        for (auto n: V[e.to].node) {
            double cost = e.cost + n.cost;
            if (D[n.to] <= cost)
                continue;
            D[n.to] = cost;
            q.push(Edge{n.to, cost});
        }
    }

    cout << OF64 << D[1] << endl;
    return 0;
}