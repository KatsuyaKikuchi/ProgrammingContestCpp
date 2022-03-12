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

ll N, M;
vector<pll> A, B;

bool U[10][10];

bool check(vector<ll> v) {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    A.resize(M);
    B.resize(M);

    memset(U, false, sizeof(U));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
    }
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
    }

    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    do {

    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
    return 0;
}