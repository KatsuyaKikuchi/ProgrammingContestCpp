#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll SIZE = 2;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<pll> node;
    bool L = false;
    ll K;
};

struct Data {
    ll cost;
    ll index;
    ll start;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K, L;
    cin >> N >> M >> K >> L;
    vector<Vertex> V(N);
    REP(i, N) {
        cin >> V[i].K;
    }
    REP(i, L) {
        ll b;
        cin >> b;
        V[b - 1].L = true;
    }

    REP(_, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.emplace_back(b, c);
        V[b].node.emplace_back(a, c);
    }

    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    vector<vector<pll>> D(N, vector<pll>(SIZE, pll(INF, -1)));
    REP(i, N) {
        if (!V[i].L)
            continue;
        q.push(Data{0, i, V[i].K});
        D[i][0] = pll(0, V[i].K);
    }

    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        bool use = false;
        REP(i, SIZE) {
            if (D[t.index][i].second == t.start &&
                D[t.index][i].first == t.cost) {
                use = true;
            }
        }
        if (!use)
            continue;

        for (auto n: V[t.index].node) {
            ll cost = n.second + t.cost;
            ll nxt = n.first;
            ll index = -1;
            REP(i, SIZE) {
                if (D[nxt][i].first <= cost) {
                    if (D[nxt][i].second == t.start) {
                        index = -1;
                        break;
                    }
                    continue;
                }
                index = i;
                if (D[nxt][i].second == t.start) {
                    break;
                }
            }

            if (index < 0)
                continue;
            D[nxt][index] = pll(cost, t.start);
            sort(D[nxt].begin(), D[nxt].end(), [](pll a, pll b) { return a.first < b.first; });
            q.push(Data{cost, nxt, t.start});
        }
    }

    REP(i, N) {
        ll cost = INF;
        REP(j, SIZE) {
            if (V[i].K != D[i][j].second) {
                cost = std::min(D[i][j].first, cost);
            }
        }
        if (cost == INF)
            cost = -1;
        cout << cost << " ";
    }
    cout << endl;
    return 0;
}