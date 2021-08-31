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

char chars[5] = {'A', 'I', 'U', 'E', 'O'};

ll change(char from, char to) {
    if (from == to)
        return 0;
    ll type0 = 0, type1 = 0;
    REP(i, 5) {
        if (from == chars[i])type0 = 1;
        if (to == chars[i])type1 = 1;
    }
    if (type0 == type1)
        return 2;
    return 1;
}

ll solver(string s) {
    ll ret = INF;
    for (char c = 'A'; c <= 'Z'; ++c) {
        ll sum = 0;
        REP(i, s.length()) {
            sum += change(s[i], c);
        }
        ret = std::min(sum, ret);
    }
    return ret;
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/QualificationRound/Input/A1.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/QualificationRound/Output/A1.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        string S;
        rs >> S;
        ws << "Case #" << i + 1 << ": " << solver(S) << endl;
    }
    return 0;
}