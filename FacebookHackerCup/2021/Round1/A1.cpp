#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

ll solve(const string &S, bool right) {
    ll N = S.length();
    ll ret = 0;
    REP(i, N) {
        if (right && S[i] == 'X') {
            ret++;
            right = false;
        } else if (!right && S[i] == 'O') {
            ret++;
            right = true;
        }
    }
    return ret;
}

ll solver(string &S) {
    return std::min(solve(S, false), solve(S, true));
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/Round1/Input/A1.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round1/Output/A1.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N;
        rs >> N;
        string S;
        rs >> S;
        ws << "Case #" << i + 1 << ": " << solver(S) << endl;
    }
    return 0;
}