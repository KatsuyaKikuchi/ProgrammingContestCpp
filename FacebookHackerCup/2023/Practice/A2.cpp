#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e17;
const long double PI = 3.1415926535897932384626433832795028841971;

bool check(ll A, ll B, ll C, ll K) {
    ll x = C / B;
    ll p = 2L * x;
    x -= std::max(0LL, (p - K));
    ll y = (C - B * x) / A;
    return K + 1 <= 2LL * y + 2LL * x && K <= y + 2LL * x;
}

ll solver(ll A, ll B, ll C) {
    if (A >= B) {
        ll b = C / B;
        return 2LL * b - 1;
    }
    ll ret = 0, ng = INF;
    while (abs(ret - ng) > 1) {
        ll m = (ret + ng) / 2;
        if (check(A, B, C, m))
            ret = m;
        else
            ng = m;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string inputFileName = "../FacebookHackerCup/2023/Practice/Input/A2.txt";
    ifstream rs;
    rs.open(inputFileName);

    string outputFileName = "../FacebookHackerCup/2023/Practice/Output/A2_out.txt";
    ofstream ws;
    ws.open(outputFileName, std::ios::out);

    ll T;
    rs >> T;
    REP(i, T) {
        ll A, B, C;
        rs >> A >> B >> C;
        ws << "Case #" << i + 1 << ": " << solver(A, B, C) << endl;
    }
    return 0;
}