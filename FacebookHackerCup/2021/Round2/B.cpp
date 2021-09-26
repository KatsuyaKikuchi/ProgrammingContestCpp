#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 1000000007;

struct Vertex {
    vector<pll> node;
    ll F;
};

struct LowestCommonAncestor {

    LowestCommonAncestor(int N, int root = 0)
            : mVertexNum(N),
              mRoot(root) {
        init();
    }

    void init() {
        for (int i = 0; i < static_cast<int>(mGraph.size()); ++i) {
            mGraph[i].clear();
        }
        mGraph.clear();
        for (int i = 0; i < static_cast<int>(mParent.size()); ++i) {
            mParent[i].clear();
        }
        mParent.clear();
        mDepth.clear();

        mGraph.resize(mVertexNum);
        mParent.resize(MAX_LOG_V, vector<int>(mVertexNum));
        mDepth.resize(mVertexNum);
    }

    void addEdge(int a, int b) {
        mGraph[a].push_back(b);
        mGraph[b].push_back(a);
    }

    void construct() {
        //! 根付き木に変換
        struct Data {
            int v;
            int p;
            int d;
        };
        stack<Data> s;
        s.push(Data{mRoot, -1, 0});
        while (!s.empty()) {
            auto t = s.top();
            s.pop();

            int v = t.v, p = t.p, d = t.d;

            mParent[0][v] = p;
            mDepth[v] = d;
            for (int i = 0; i < static_cast<int>(mGraph[v].size()); ++i) {
                int n = mGraph[v][i];
                if (n == p)
                    continue;
                s.push(Data{n, v, d + 1});
            }
        }

        //! 2^k回辿った親をキャッシュ
        for (int k = 0; k + 1 < MAX_LOG_V; ++k) {
            for (int i = 0; i < mVertexNum; ++i) {
                if (mParent[k][i] < 0)
                    mParent[k + 1][i] = -1;
                else
                    mParent[k + 1][i] = mParent[k][mParent[k][i]];
            }
        }
    }

    int lca(int a, int b) {
        if (mDepth[a] > mDepth[b])
            swap(a, b);
        //! aとbの深さが同じになるまで親をたどる
        for (int k = 0; k < MAX_LOG_V; ++k) {
            if ((mDepth[b] - mDepth[a]) >> k & 1)
                b = mParent[k][b];;
        }
        if (a == b)
            return a;
        for (int k = MAX_LOG_V - 1; k >= 0; --k) {
            if (mParent[k][a] != mParent[k][b]) {
                a = mParent[k][a];
                b = mParent[k][b];
            }
        }
        return mParent[0][a];
    }

    int length(int a, int b) {
        int p = lca(a, b);
        return mDepth[a] + mDepth[b] - 2 * mDepth[p];
    }

    vector<vector<int>> mGraph;
    vector<vector<int>> mParent;
    vector<int> mDepth;
    int mVertexNum;
    int mRoot;
    const int MAX_LOG_V = 50;
};

ll solver(vector<Vertex> &V, LowestCommonAncestor &lca) {
    ll N = V.size();

    vector<ll> C(N, 0);
    vector<vector<ll>> F(N);
    REP(i, N) {
        F[V[i].F].push_back(i);
    }

    for (auto &f: F) {
        if (f.size() <= 1)
            continue;
        ll index = f[0];
        FOR(i, f.size(), 1) {
            ll t = f[i];
            C[index]++;
            C[t]++;
            index = lca.lca(index, t);
            C[index] -= 2;
        }
    }

    struct Data {
        ll v;
        ll p;
    };

    stack<Data> s;
    vector<Data> v;
    s.push(Data{0, -1});
    while (!s.empty()) {
        auto d = s.top();
        s.pop();
        v.push_back(d);
        for (auto &n: V[d.v].node) {
            if (n.first == d.p)
                continue;
            s.push(Data{n.first, d.v});
        }
    }

    reverse(v.begin(), v.end());

    ll ans = N - 1;

    REP(i, N) {
        ll index = v[i].v;
        ll parent = v[i].p;
        if (C[index] > 0)
            ans--;
        if (parent >= 0)
            C[parent] += C[index];
    }

    return ans;
}

int main() {
    string inputFileName = "../FacebookHackerCup/2021/Round2/Input/B.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round2/Output/B.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N;
        rs >> N;
        vector<Vertex> V(N);
        LowestCommonAncestor lca = LowestCommonAncestor(N);
        REP(j, N - 1) {
            ll a, b;
            rs >> a >> b;
            a--;
            b--;
            V[a].node.emplace_back(b, j);
            V[b].node.emplace_back(a, j);
            lca.addEdge(a, b);
        }
        REP(j, N) {
            rs >> V[j].F;
            V[j].F--;
        }

        lca.construct();
        ws << "Case #" << i + 1 << ": " << solver(V, lca) << endl;
    }
    return 0;
}