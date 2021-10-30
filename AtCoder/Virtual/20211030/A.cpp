#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

void rot(vector<string> &S) {
    ll N = S.size();
    vector<vector<char>> T(N, vector<char>(N));
    REP(i, N) {
        REP(j, N) {
            T[j][N - 1 - i] = S[i][j];
        }
    }
    REP(i, N) {
        REP(j, N) {
            S[i][j] = T[i][j];
        }
    }
}

vector<string> zip(const vector<string> &S) {
    vector<string> ret;
    ll top = INF, bottom = -1, left = INF, right = -1;
    ll N = S.size();
    REP(i, N) {
        REP(j, N) {
            if (S[i][j] == '.')
                continue;
            top = std::min(top, i);
            bottom = std::max(bottom, i);
            left = std::min(left, j);
            right = std::max(right, j);
        }
    }
    for (ll i = top; i <= bottom; ++i) {
        string s = "";
        for (ll j = left; j <= right; ++j) {
            s.push_back(S[i][j]);
        }
        ret.push_back(s);
    }
    return ret;
}

bool check(vector<string> &S, vector<string> &T) {
    if (S.size() != T.size())
        return false;
    if (S[0].size() != T[0].size())
        return false;
    REP(i, S.size()) {
        REP(j, S[i].size()) {
            if (S[i][j] != T[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<string> S(N), T(N);
    REP(i, N) {
        cin >> S[i];
    }
    REP(i, N) {
        cin >> T[i];
    }

    REP(_, 4) {
        auto s = zip(S);
        auto t = zip(T);
        if (check(s, t)) {
            cout << "Yes" << endl;
            return 0;
        }
        rot(S);
    }
    cout << "No" << endl;

    return 0;
}