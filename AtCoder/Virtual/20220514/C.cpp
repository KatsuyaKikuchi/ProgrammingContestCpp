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

    REP(i, N) {
        sort(V[i].node.begin(), V[i].node.end());
    }

    vector<bool> seen(N, false);
    vector<ll> I(N, 0);
    vector<ll> P(N, -1);
    ll index = 0;
    while (true) {
        seen[index] = true;
        cout << index + 1 << " ";
        while (I[index] < V[index].node.size()) {
            ll n = V[index].node[I[index]];
            if (seen[n])
                I[index]++;
            else
                break;
        }
        if (I[index] >= V[index].node.size()) {
            if (index == 0)
                break;
            index = P[index];
            continue;
        }
        ll nxt = V[index].node[I[index]];

        P[nxt] = index;
        index = nxt;
    }
    cout << endl;

    return 0;
}