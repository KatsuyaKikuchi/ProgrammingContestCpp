#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

bool solver(ll S, ll D, ll K) {
    ll p = S * 2LL + D * 2LL;
    ll b = S + 2LL * D;
    return b >= K && p >= K + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string inputFileName = "../FacebookHackerCup/2023/Practice/Input/A.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2023/Practice/Output/A.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll S, D, K;
        rs >> S >> D >> K;
        ws << "Case #" << i + 1 << ": ";
        if (solver(S, D, K))
            ws << "YES" << endl;
        else
            ws << "NO" << endl;
    }
    return 0;
}