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

struct Vertex {
    vector<ll> node;
};

bool solve(vector<Vertex> &V) {
    ll N = V.size();
    REP(i, N) {
        if (V[i].node.size() >= 3) {
            return false;
        }
    }
    vector<bool> E(N, false);
    {
        queue<ll> q;
        REP(i, N) {
            if (V[i].node.size() == 0)
                E[i] = true;
            else if (V[i].node.size() == 1) {
                q.push(i);
                E[i] = true;
            }

        }

        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                if (E[n])
                    continue;
                q.push(n);
                E[n] = true;
            }
        }

        ll count = 0;
        REP(i, N) {
            if (!E[i])
                count++;
        }

        if (count == 0 )
            return true;
        return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    if (solve(V))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}