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

ll N, K;
ll MAX;
vector<ll> A;
std::set<ll> cost;

void dfs(ll index = 0, ll sum = 0) {
    cost.insert(sum);
    if (sum > MAX) {
        return;
    }
    while (sum <= MAX) {
        if (index + 1 < N)
            dfs(index + 1, sum);
        sum += A[index];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    MAX = A[0] * K;

    dfs();

    vector<ll> v;
    for (auto t: cost) {
        v.push_back(t);
    }
    cout << v[K] << endl;

    return 0;
}