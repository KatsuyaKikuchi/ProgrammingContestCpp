#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 1000000007;

ll solver(vector<ll> &S, vector<vector<ll>> &P) {
    ll N = P.size();
    ll M = S.size();
    cout << N << " " << M << endl;
    sort(S.begin(), S.end());
    REP(i, N) {
        sort(P[i].begin(), P[i].end());
    }

    ll ans = 0;
    queue<ll> p, q;
    REP(i, M) {
        q.push(S[i]);
    }

    REP(i, N) {
        ll index = 0;
        queue<ll> nxtP, nxtQ;
        while (!q.empty() || !p.empty()) {
            bool useQ = false;
            if (!q.empty()) {
                if (!p.empty()) {
                    if (q.front() < p.front()) {
                        useQ = true;
                    }
                } else {
                    useQ = true;
                }
            }

            ll val;
            if (useQ) {
                val = q.front();
                q.pop();
            } else {
                val = p.front();
                p.pop();
            }

            bool find = false;
            while (index < M && P[i][index] <= val) {
                if (P[i][index] == val) {
                    if (useQ) {
                        nxtQ.push(val);
                    } else {
                        nxtP.push(val);
                    }
                    find = true;
                    index++;
                    break;
                }
                nxtP.push(P[i][index]);
                index++;
            }

            if (!find && !useQ) {
                ans++;
            }
        }
        while (index < M) {
            nxtP.push(P[i][index]);
            index++;
        }
        swap(p, nxtP);
        swap(q, nxtQ);
    }

    return ans;
}

int main() {
    string inputFileName = "../FacebookHackerCup/2021/Round2/Input/A.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2021/Round2/Output/A.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll N, M;
        rs >> N >> M;
        vector<ll> S(M);
        REP(j, M) {
            rs >> S[j];
        }
        vector<vector<ll>> P(N);
        REP(j, N) {
            P[j].resize(M);
            REP(k, M) {
                rs >> P[j][k];
            }
        }
        ws << "Case #" << i + 1 << ": " << solver(S, P) << endl;
    }
    return 0;
}