//
// Created by katsuya kikuchi on 2021/09/12.
//

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
const ll MOD = 1000000007;

ll solver(string &S) {
    ll N = S.length();
    ll ret = 0;
    ll s = 0;
    ll prev = N;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] != 'F') {
            if (S[prev] != S[i]) {
                s = (s + N - prev) % MOD;
            }
            prev = i;
        }
        ret = (ret + s) % MOD;
    }
    return ret;
}

int main() {

    string inputFileName = "../FacebookHackerCup/2021/Round1/Input/A2.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round1/Output/A2.txt";
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