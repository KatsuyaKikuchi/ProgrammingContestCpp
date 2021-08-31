#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

ll solver(string s, const vector<string> &path) {
    ll ret = INF;
    ll size = 30;
    vector<vector<ll>> cost(size, vector<ll>(size, INF));
    REP(i, size) {
        cost[i][i] = 0;
    }
    REP(i, path.size()) {
        ll from = path[i][0] - 'A', to = path[i][1] - 'A';
        cost[from][to] = 1;
    }

    REP(k, size) {
        REP(i, size) {
            REP(j, size) {
                cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        ll sum = 0;
        REP(i, s.length()) {
            ll from = s[i] - 'A', to = c - 'A';
            sum += cost[from][to];
        }
        ret = std::min(sum, ret);
    }
    if (ret == INF) {
        return -1;
    }
    return ret;
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/QualificationRound/Input/A2.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/QualificationRound/Output/A2.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        string S;
        rs >> S;
        ll K;
        rs >> K;
        vector<string> path(K);
        REP(j, K) {
            rs >> path[j];
        }
        ws << "Case #" << i + 1 << ": " << solver(S, path) << endl;
    }
    return 0;
}