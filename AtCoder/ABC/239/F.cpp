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

ll N, M;
ll D[200005];
vector<pll> E;

struct UnionFind {
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return x;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return x;
    }

    vector<vector<int>> groups() {
        vector<ll> g;
        for (int i = 0; i < parent.size(); ++i) {
            ll p = find(i);
            g.push_back(p);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());

        vector<vector<int>> ret(g.size());
        for (int i = 0; i < parent.size(); ++i) {
            auto index = lower_bound(g.begin(), g.end(), find(i)) - g.begin();
            ret[index].push_back(i);
        }
        return ret;
    }

    vector<int> parent;
    vector<int> rank;
};


bool solve() {

    UnionFind uf(N);
    REP(i, E.size()) {
        ll a = E[i].first, b = E[i].second;
        if (uf.same(a, b))
            return false;
        uf.unit(a, b);
        D[a]--;
        D[b]--;
        if (D[a] < 0 || D[b] < 0)
            return false;
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });

    auto group = uf.groups();
    vector<stack<ll> > S(group.size());
    REP(i, group.size()) {
        auto &g = group[i];
        if (g.size() == 0)
            continue;
        ll sum = 0;
        for (auto n: g) {
            if (D[n] == 0)
                continue;
            sum += D[n];
            S[i].push(n);
        }

        if (sum == 0)
            return false;

        q.push(pll(i, sum));
    }

    vector<pll> ans;

    while (q.size() > 1) {
        pll t0 = q.top();
        q.pop();
        pll t1 = q.top();
        q.pop();

        if (t0.second == 0 || t1.second == 0)
            return false;

        ll s0 = S[t0.first].top();
        ll s1 = S[t1.first].top();


        ans.push_back(pll(s0 + 1, s1 + 1));
        t0.second--;
        t1.second--;
        D[s0]--;
        D[s1]--;
        if (D[s0] == 0)
            S[t0.first].pop();
        if (D[s1] == 0)
            S[t1.first].pop();

        pll nxt(INF, t0.second + t1.second);

        if (S[t0.first].size() > S[t1.first].size()) {
            nxt.first = t0.first;
            while (!S[t1.first].empty()) {
                auto s = S[t1.first].top();
                S[t1.first].pop();
                S[t0.first].push(s);
            }
        } else {
            nxt.first = t1.first;
            while (!S[t0.first].empty()) {
                auto s = S[t0.first].top();
                S[t0.first].pop();
                S[t1.first].push(s);
            }
        }

        q.push(nxt);
    }

    REP(i, N) {
        if (D[i] != 0)
            return false;
    }

    REP(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> D[i];
    }
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        E.push_back(pll(a, b));
    }

    if (!solve()) {
        cout << -1 << endl;
    }


    return 0;
}