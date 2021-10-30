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

struct Data {
    ll r, c, a;
    ll index;
};

struct Vertex {
    vector<ll> to;
    vector<ll> from;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> H >> W >> N;
    vector<Data> D(N);
    vector<vector<pll>> HH(H), WW(W);
    REP(i, N) {
        cin >> D[i].r >> D[i].c >> D[i].a;
        D[i].index = i;
        HH[D[i].r - 1].push_back(pll(i, D[i].a));
        WW[D[i].c - 1].push_back(pll(i, D[i].a));
    }
    vector<Vertex> V(N);
    REP(i, H) {
        sort(HH[i].begin(), HH[i].end(), [](pll a, pll b) { return a.second < b.second; });
        ll idx = V.size();
        V.emplace_back();
        ll pi = -1;
        REP(j, HH[i].size()) {

            if (j > 0 && HH[i][j].second != HH[i][j - 1].second) {
                pi = idx;

                idx = V.size();
                V.emplace_back();
            }
            if (pi >= 0) {
                V[pi].to.push_back(HH[i][j].first);
                V[HH[i][j].first].from.push_back(pi);
            }
            V[idx].from.push_back(HH[i][j].first);
            V[HH[i][j].first].to.push_back(idx);
        }
    }
    REP(i, W) {
        sort(WW[i].begin(), WW[i].end(), [](pll a, pll b) { return a.second < b.second; });
        ll idx = V.size();
        V.emplace_back();
        ll pi = -1;
        REP(j, WW[i].size()) {

            if (j > 0 && WW[i][j].second != WW[i][j - 1].second) {
                pi = idx;

                idx = V.size();
                V.emplace_back();
            }
            if (pi >= 0) {
                V[pi].to.push_back(WW[i][j].first);
                V[WW[i][j].first].from.push_back(pi);
            }
            V[idx].from.push_back(WW[i][j].first);
            V[WW[i][j].first].to.push_back(idx);
        }
    }

    sort(D.begin(), D.end(), [](Data a, Data b) { return a.a > b.a; });
    vector<ll> C(V.size(), 0);
    REP(i, N) {
        ll index = D[i].index;
        for (auto &pr: V[index].to) {
            C[index] = std::max(C[index], C[pr]);
        }
        for (auto &nxt: V[index].from) {
            C[nxt] = std::max(C[nxt], C[index] + 1);
        }
    }

    REP(i, N) {
        cout << C[i] << endl;
    }

    return 0;
}