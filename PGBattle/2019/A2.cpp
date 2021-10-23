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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if (S == "AtCoder")
        cout << "Yes" << endl;
    else {
        REP(i, S.size()) {
            if (S[i] >= 'A' && S[i] <= 'Z')
                S[i] = S[i] - 'A' + 'a';
        }
        if (S == "atcoder")
            cout << "Maybe" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}