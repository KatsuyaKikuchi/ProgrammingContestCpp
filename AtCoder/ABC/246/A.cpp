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

    vector<ll> x(3), y(3);
    REP(i, 3) {
        cin >> x[i] >> y[i];
    }
    ll ax, ay;
    if (x[0] == x[1])
        ax = x[2];
    else if (x[0] == x[2])
        ax = x[1];
    else
        ax = x[0];

    if (y[0] == y[1])
        ay = y[2];
    else if (y[0] == y[2])
        ay = y[1];
    else
        ay = y[0];

    cout<<ax<<" "<<ay<<endl;
    return 0;
}