#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
ll MAX = 100000;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<bool> prime(MAX, true);
    prime[0] = prime[1] = false;
    FOR(i, MAX, 2) {
        if (!prime[i])
            continue;
        for (ll j = i + i; j < MAX; j += i)
            prime[j] = false;
    }

    for (ll t = A; t <= B; ++t) {
        bool win = true;
        for (ll a = C; a <= D; ++a) {
            ll x = t + a;

            if (prime[x])
                win = false;
        }

        if (win) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }

    cout << "Aoki" << endl;

    return 0;
}