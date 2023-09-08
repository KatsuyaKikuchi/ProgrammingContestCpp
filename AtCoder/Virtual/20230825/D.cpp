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


struct Vertex {
    vector<ll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);

    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    vector<bool> seen(N, false);
    queue<ll> q;
    ll index = 0;
    ll ans = 0;
    vector<ll> X(N);
    {
        q.push(0);
        X[0] = A[index];
        index++;
        seen[0] = true;
    }
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        for (auto n: V[t].node) {
            if (seen[n])
                continue;
            seen[n] = true;
            q.push(n);
            X[n] = A[index];
            index++;
            ans += std::min(X[n], X[t]);
        }
    }
    cout << ans << endl;
    REP(i, N) {
        cout << X[i] << " ";
    }
    cout << endl;
    return 0;
}