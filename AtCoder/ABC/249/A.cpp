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
    ll A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    ll S = 0, T = 0;
    REP(i, X) {
        ll t = i;
        ll a = t % (A + C);
        ll b = t % (D + F);

        if (a <= A) {
            S += B;
        }
        if (b <= D)
            T += E;
    }

    if (S == T)
        cout << "Draw" << endl;
    else if (S < T)
        cout << "Aoki" << endl;
    else
        cout << "Takahashi" << endl;
    return 0;
}