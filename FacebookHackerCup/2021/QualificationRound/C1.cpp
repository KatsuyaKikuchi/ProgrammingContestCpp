#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

struct Vertex {
    ll value;
    vector<ll> next;
};

ll dfs(const vector<Vertex> &V, ll index, ll parent, ll value = 0) {
    ll ret = value + V[index].value;
    for (auto nxt: V[index].next) {
        if (nxt == parent)continue;
        ret = std::max(ret, dfs(V, nxt, index, value + V[index].value));
    }
    return ret;
}

ll solver(vector<Vertex> &V) {
    vector<ll> v(2, 0);
    for (auto n: V[0].next) {
        v.push_back(dfs(V, n, 0));
    }
    sort(v.begin(), v.end(), greater<ll>());
    return V[0].value + v[0] + v[1];
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/QualificationRound/Input/C1.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/QualificationRound/Output/C1.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N;
        rs >> N;
        vector<Vertex> V(N);
        REP(j, N) {
            rs >> V[j].value;
        }
        REP(j, N - 1) {
            ll a, b;
            rs >> a >> b;
            a--;
            b--;
            V[a].next.push_back(b);
            V[b].next.push_back(a);
        }
        ws << "Case #" << i + 1 << ": " << solver(V) << endl;
    }
    return 0;
}