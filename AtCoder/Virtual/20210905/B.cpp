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

ll C[100005];
ll T[2] = {6, 9};

int main() {
    ll N;
    cin >> N;
    REP(i, N + 1) {
        C[i] = i;
    }
    REP(i, 2) {
        REP(j, N) {
            ll n = T[i];
            while (j + n <= N) {
                C[j + n] = std::min(C[j + n], C[j] + 1);
                n *= T[i];
            }
        }
    }

    cout << C[N] << endl;
    return 0;
}