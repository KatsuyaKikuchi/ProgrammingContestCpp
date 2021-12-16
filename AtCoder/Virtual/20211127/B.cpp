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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll M = S.length();

    vector<ll> ans(M, -1);
    ll index = 1;
    while (true) {
        bool fin = true;
        REP(i, M) {
            if (ans[i] == -1) {
                fin = false;
                break;
            }
        }
        if (fin)
            break;

        ll s, e;
        REP(i, M) {
            if (ans[i] == -1) {
                s = i;
                break;
            }
        }
        REP(i, ans.size()) {
            if (ans[M - 1 - i] == -1 && S[s] != S[M - 1 - i]) {
                e = M - 1 - i;
            }
        }
        char sc = S[s], ec = S[e];

        vector<ll> C(M + 5, 0);
        REP(i, M) {
            if (ans[i] == -1 && S[i] != S[s] && S[i] != S[e])
                C[i]++;
            C[i + 1] += C[i];
        }

        while (true) {
            ans[s] = ans[e] = index;

            ll nx = s;
            while (nx < M - 1) {
                nx++;
                if (S[nx] == sc && ans[nx] == -1)
                    break;
            }
            ll ne = e;
            while (ne > 0) {
                ne--;
                if (S[ne] == ec && ans[ne] == -1)
                    break;
            }

        }

        index++;
    }

    REP(i, M) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}