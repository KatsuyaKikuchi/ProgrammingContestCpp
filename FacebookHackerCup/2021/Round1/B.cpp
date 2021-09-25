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
const ll MOD = 1000000007;

vector<vector<ll>> ans;

bool solver(ll N, ll M, ll A, ll B) {
    ll num = N + M - 1;
    if (num > A || num > B)
        return false;
    ans.resize(N);
    REP(i, N) {
        ans[i].resize(M);
        REP(j, M) {
            ans[i][j] = 1;
        }
    }
    ans[0][0] += A - num;
    ans[0][M - 1] += B - num;
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/Round1/Input/B.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round1/Output/B.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N, M, A, B;
        rs >> N >> M >> A >> B;
        ws << "Case #" << i + 1 << ": ";
        bool f = solver(N, M, A, B);
        if (f)
            ws << "Possible" << endl;
        else
            ws << "Impossible" << endl;

        if (f) {
            REP(r, N) {
                REP(c, M) {
                    ws << ans[r][c] << " ";
                }
                ws << endl;
            }
        }
    }

    return 0;
}