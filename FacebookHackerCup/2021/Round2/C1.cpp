#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 1000000007;

ll solve(const vector<string> &S, ll K) {
    ll N = S.size();
    ll M = S[0].size();
    vector<ll> C(M, 0);
    REP(j, M) {
        REP(i, K) {
            if (S[i][j] == 'X')
                C[j]++;
        }
    }

    ll ans = INF;
    REP(i, N) {
        // 上にi回移動させた後を調べる
        ll sum = 0;
        REP(j, M) {
            char c = K + i < N ? S[K + i][j] : '.';
            if (c == 'X') {
                C[j]++;
                sum++;
            } else if (C[j] > K) {
                sum++;
            }
        }
        ans = std::min(ans, sum + i);
    }

    return ans;
}

ll solver(vector<string> &S, ll K) {
    ll R = S.size();

    ll ans = solve(S, K);
    REP(i, R / 2) {
        swap(S[i], S[R - 1 - i]);
    }
    K = R - 1 - K;
    ans = std::min(ans, solve(S, K));
    return ans;
}

int main() {
    string inputFileName = "../FacebookHackerCup/2021/Round2/Input/C1.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round2/Output/C1.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll R, C, K;
        rs >> R >> C >> K;
        K--;
        vector<string> S(R);
        REP(j, R) {
            rs >> S[j];
        }
        ws << "Case #" << i + 1 << ": " << solver(S, K) << endl;
    }
    return 0;
}