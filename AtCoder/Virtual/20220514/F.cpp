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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;

    stack<ll> C[30];
    REP(i, N) {
        C[S[i] - 'a'].push(i);
    }

    ll index = N;
    REP(i, N) {
        REP(j, S[i] - 'a') {
            if (C[j].empty())
                continue;
            if (C[j].top() < i)
                continue;
            ll idx = C[j].top();
            C[j].pop();
            swap(S[i], S[idx]);
            index = idx;
            break;
        }
        REP(j, 30) {
            while (!C[j].empty() && C[j].top() > index) {
                C[j].pop();
            }
        }
    }

    cout << S << endl;

    return 0;
}