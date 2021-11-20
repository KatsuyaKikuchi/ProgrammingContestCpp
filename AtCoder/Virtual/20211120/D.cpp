#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

ll N, M, V, P;
vector<ll> A;

bool check(ll index) {
    ll value = A[index] + M;
    ll sum = M * V - M;
    ll count = 0;
    vector<ll> C;
    REP(i, N) {
        if (i == index)
            continue;
        if (A[i] > value) {
            count++;
            sum -= M;
            continue;
        }
        ll s = std::min(M, std::max(0LL, value - A[i]));
        C.push_back(M - s);
        sum -= s;
    }

    if (count >= P)
        return false;

    sort(C.begin(), C.end(), greater<ll>());
    REP(i, P - count - 1) {
        sum -= C[i];
    }

    return sum <= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> V >> P;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll ok = 0, ng = N;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok + 1 << endl;
    return 0;
}