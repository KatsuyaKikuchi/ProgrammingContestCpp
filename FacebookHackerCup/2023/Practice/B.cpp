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

bool solver(ll R, ll C, ll A, ll B) {
    return R > C;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string inputFileName = "../FacebookHackerCup/2023/Practice/Input/B.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2023/Practice/Output/B_out.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll R, C, A, B;
        rs >> R >> C >> A >> B;
        ws << "Case #" << i + 1 << ": ";

        if (solver(R, C, A, B))
            ws << "YES" << endl;
        else
            ws << "NO" << endl;
    }
    return 0;
}