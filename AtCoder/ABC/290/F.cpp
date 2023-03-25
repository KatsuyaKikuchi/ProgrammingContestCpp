#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

std::map<ll, ll> ans;

ll solver(int N, int K, vector<ll> row, vector<ll> col) {
    vector<ll> values;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            values.push_back(row[i] * col[j]);
    sort(values.begin(), values.end());
    return values[K - 1];
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> Row(N), Col(N);
    for (int i = 0; i < N; ++i) cin >> Row[i];
    for (int i = 0; i < N; ++i) cin >> Col[i];

    cout << solver(N, K, Row, Col) << endl;
    return 0;
}