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

// 強連結成分分解
class SccGraph {
public:
    SccGraph(int n) {
        vertices.resize(n);
    }

    void addEdge(int from, int to) {
        vertices[from].to.push_back(to);
        vertices[to].from.push_back(from);
    }

    vector<vector<int>> scc() {
        vector<int> v;
        {
            vector<bool> seen(vertices.size(), false);
            for (int i = 0; i < vertices.size(); ++i) {
                if (seen[i])
                    continue;
                dfs(i, v, seen);
            }
        }
        vector<vector<int>> ret;
        {
            vector<bool> seen(vertices.size(), false);
            for (int i = v.size() - 1; i >= 0; --i) {
                int index = v[i];
                if (seen[index])
                    continue;
                vector<int> t;
                seen[index] = true;
                stack<int> stk;
                stk.push(index);
                while (!stk.empty()) {
                    ll n = stk.top();
                    stk.pop();
                    t.push_back(n);
                    for (auto &nxt: vertices[n].from) {
                        if (seen[nxt])
                            continue;
                        seen[nxt] = true;
                        stk.push(nxt);
                    }
                }
                ret.push_back(t);
            }
        }
        return ret;
    }

private:
    void dfs(int index, vector<int> &v, vector<bool> &seen) {
        seen[index] = true;
        for (auto &nxt: vertices[index].to) {
            if (seen[nxt])
                continue;
            dfs(nxt, v, seen);
        }
        v.push_back(index);
    }

    struct Vertex {
        vector<int> to;
        vector<int> from;
    };
    vector<Vertex> vertices;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    SccGraph graph(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.addEdge(a, b);
    }
    auto v = graph.scc();

    ll ans = 0;
    for (auto &t: v) {
        ll n = t.size();
        ans += n * (n - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}