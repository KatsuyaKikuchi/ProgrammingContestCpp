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
    double x[2], y[2];
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];

    double dir[2] = {(x[1] - x[0]) * 0.5, (y[1] - y[0]) * 0.5};
    double theta = ((360.0 / N) * (N / 2 - 1)) / 180.0 * PI;

    //cout << OF64 << dir[0] << " " << dir[1] << " " << theta << endl;

    double c = cos(-theta);
    double s = sin(-theta);
    double rot[2] = {dir[0] * c - s * dir[1], dir[0] * s + dir[1] * c};

    //cout << OF64 << rot[0] << " " << rot[1] << endl;

    double ax = x[0] + dir[0] + rot[0];
    double ay = y[0] + dir[1] + rot[1];
    cout << OF64 << ax << " " << ay << endl;
    return 0;
}