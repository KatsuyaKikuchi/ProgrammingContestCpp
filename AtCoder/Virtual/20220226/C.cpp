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

ll X, Y;
ll A[3];

bool check(vector<ll> v) {

    {
        ll x = 0;
        REP(i, v.size()) {
            ll index = v[i];
            ll d = (A[index] + Y - 1) / Y;
            x += d;
        }
        if (x <= X)
            return true;
    }
    {
        ll y = 0;
        REP(i, v.size()) {
            ll index = v[i];
            ll d = (A[index] + X - 1) / X;
            y += d;
        }
        if (y <= Y)
            return true;
    }
    {
        ll dy = (A[v[0]] + X - 1) / X;
        if (dy < Y) {
            ll x = 0;
            FOR(i, v.size(), 1) {
                ll index = v[i];
                ll d = (A[index] + (Y - dy) - 1) / (Y - dy);
                x += d;
            }
            if (x <= X)
                return true;
        }
    }
    {
        ll dx = (A[v[0]] + Y - 1) / Y;
        if (dx < X) {
            ll y = 0;
            FOR(i, v.size(), 1) {
                ll index = v[i];
                ll d = (A[index] + (X - dx) - 1) / (X - dx);
                y += d;
            }
            if (y <= Y)
                return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> X >> Y >> A[0] >> A[1] >> A[2];
    vector<ll> v = {0, 1, 2};
    do {
        if (check(v)) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;

    return 0;
}