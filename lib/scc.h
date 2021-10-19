//
// Created by katsuya kikuchi on 2021/10/19.
//

#ifndef PROGRAMMINGCONTESTCPP_SCC_H
#define PROGRAMMINGCONTESTCPP_SCC_H

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

#endif //PROGRAMMINGCONTESTCPP_SCC_H
