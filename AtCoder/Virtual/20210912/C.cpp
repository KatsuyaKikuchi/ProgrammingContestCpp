#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

char next(char a, char b) {
    if (a == 'P') {
        if (b == 'S')return b;
        return a;
    }
    if (a == 'S') {
        if (b == 'R')return b;
        return a;
    }

    if (b == 'P')return b;
    return a;
}

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    REP(_, K) {
        string s = "";
        REP(i, N) {
            ll a = (2 * i) % N;
            ll b = (2 * i + 1) % N;
            s.push_back(next(S[a], S[b]));
        }
        S = s;
    }
    cout << S[0] << endl;
    return 0;
}