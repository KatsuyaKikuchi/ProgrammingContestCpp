#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S.push_back('z');
    N++;

    string ans = "";
    vector<queue<ll>> s(30);
    REP(i, N - K) {
        s[S[i] - 'a'].push(i);
    }
    FOR(i, N, N - K) {
        ll index = -1;
        REP(j, s.size()) {
            if (s[j].empty())
                continue;
            ans.push_back('a' + j);
            index = s[j].front();
            break;
        }
        REP(j, s.size()) {
            while (!s[j].empty() && s[j].front() <= index) {
                s[j].pop();
            }
        }
        s[S[i] - 'a'].push(i);
    }
    cout << ans << endl;

    return 0;
}