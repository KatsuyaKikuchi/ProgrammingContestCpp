#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

pll check(pll minValue, pll value) {
    if (value.first != 0) {
        return minValue;
    }
    if (minValue.first > value.second) {
        return pll(value.second, 1);
    }
    if (minValue.first == value.second) {
        return pll(minValue.first, minValue.second + 1);
    }
    return minValue;
}

pll solver(vector<string> M) {
    ll N = M.size();
    pll ret(INF, INF);
    REP(i, N) {
        pll row(0, 0), col(0, 0);
        REP(j, N) {
            if (M[i][j] == 'O')row.first++;
            if (M[i][j] == '.')row.second++;
            if (M[j][i] == 'O')col.first++;
            if (M[j][i] == '.')col.second++;
        }
        ret = check(ret, row);
        ret = check(ret, col);
    }

    if (ret.first == 1) {
        vector<vector<ll>> count(N, vector<ll>(N, 0));
        REP(i, N) {
            pll row(0, 0);
            ll col = -1;
            REP(j, N) {
                if (M[i][j] == 'O')row.first++;
                if (M[i][j] == '.') {
                    row.second++;
                    col = j;
                }
            }
            if (row.first != 0 || row.second != 1)
                continue;
            count[i][col]++;
        }
        REP(i, N) {
            pll col(0, 0);
            ll row = -1;
            REP(j, N) {
                if (M[j][i] == 'O')col.first++;
                if (M[j][i] == '.') {
                    col.second++;
                    row = j;
                }
            }
            if (col.first != 0 || col.second != 1)
                continue;
            count[row][i]++;
        }

        REP(i, N) {
            REP(j, N) {
                if (count[i][j] == 2)ret.second--;
            }
        }
    }
    return ret;
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/QualificationRound/Input/B.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/QualificationRound/Output/B.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N;
        rs >> N;
        vector<string> M(N);
        REP(j, N) {
            rs >> M[j];
        }
        pll ans = solver(M);
        ws << "Case #" << i + 1 << ": ";
        if (ans.first == INF && ans.second == INF) {
            ws << "Impossible" << endl;
        } else {
            ws << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}