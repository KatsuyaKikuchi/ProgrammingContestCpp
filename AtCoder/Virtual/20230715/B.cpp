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
        dfs(mRoot, -1, 0);
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

    void dfs(int v, int p, int d) {
        mParent[0][v] = p;
        mDepth[v] = d;
        for (int i = 0; i < static_cast<int>(mGraph[v].size()); ++i) {
            int n = mGraph[v][i];
            if (n == p)
                continue;
            dfs(n, v, d + 1);
        }
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    LowestCommonAncestor lca(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        lca.addEdge(a, b);
    }
    lca.construct();

    REP(_, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        ll len = lca.length(a, b);
        if (len % 2 == 1)
            cout << "Road" << endl;
        else
            cout << "Town" << endl;
    }
    return 0;
}