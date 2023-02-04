#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
using pp = pair<double, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    ll g = -1;
    ll s = -1;
};

void solve(vector<Vertex> &T, ll index, bool &isG, ll &nxt) {
    if (T[index].g >= 0) {
        isG = true;
        nxt = T[index].g;
    } else {
        isG = false;
        nxt = T[index].s;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    pp g = pp(1, 0);
    pp s = pp(0, 0);
    vector<Vertex> G(N + 5), S(N + 5);
    REP(i, N) {
        double ng = s.first / A[i];
        double ns = g.first * A[i];
        if (ng > g.first) {
            G[i + 1].s = s.second;
            g = pp(ng, i + 1);
        } else {
            G[i + 1].g = g.second;
        }
        if (ns > s.first) {
            S[i + 1].g = g.second;
            s = pp(ns, i + 1);
        } else {
            S[i + 1].s = s.second;
        }
    }

    vector<ll> ans(N, 0);
    bool isG = true;
    ll nxt = N;
    while (nxt > 0) {
        ll index = nxt;
        bool t = isG;
        if (t) {
            solve(G, index, isG, nxt);
        } else {
            solve(S, index, isG, nxt);
        }
        if (t != isG) {
            ans[index - 1] = 1;
        }
    }

    //reverse(ans.begin(), ans.end());
    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}