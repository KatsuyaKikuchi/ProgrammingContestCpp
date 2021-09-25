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

int main() {
    ll N;
    cin >> N;
    vector<ll> T(N);
    ll s = 0;
    REP(i, N) {
        cin >> T[i];
        s += T[i];
    }

    vector<bool> V(s + 5, false);
    V[0] = true;
    REP(i, N) {
        for (ll j = s; j >= 0; --j) {
            if (!V[j])
                continue;
            if (T[i] + j <= s)
                V[T[i] + j] = true;
        }
    }
    ll ans = INF;
    REP(i, s + 1) {
        if (!V[i])
            continue;

        ans = std::min(ans, std::max(i, s - i));
    }
    cout << ans << endl;
    return 0;
}