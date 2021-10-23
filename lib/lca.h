//
// Created by katsuya kikuchi on 2021/10/23.
//

#ifndef PROGRAMMINGCONTESTCPP_LCA_H
#define PROGRAMMINGCONTESTCPP_LCA_H

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

#endif //PROGRAMMINGCONTESTCPP_LCA_H
