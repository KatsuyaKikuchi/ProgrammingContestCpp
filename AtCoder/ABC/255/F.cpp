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
    ll left, right;
};

vector<ll> P, I;
vector<ll> CP, CI;

void dfs0(const vector<Vertex> &V, ll index = 0) {
    if (index < 0)
        return;
    CP.push_back(index);
    dfs0(V, V[index].left);
    dfs0(V, V[index].right);
}

void dfs1(const vector<Vertex> &V, ll index = 0) {
    if (index < 0)
        return;
    dfs1(V, V[index].left);
    CI.push_back(index);
    dfs1(V, V[index].right);
}

bool check(const vector<Vertex> &V) {
    CP.resize(0);
    CI.resize(0);

    dfs0(V);
    dfs1(V);

    ll N = V.size();
    REP(i, N) {
        if (CP[i] != P[i])
            return false;
        if (CI[i] != I[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    P.resize(N), I.resize(N);
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }
    REP(i, N) {
        cin >> I[i];
        I[i]--;
    }

    if (P[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<pll> ans(N, pll(-1, -1));
    ll index = 0;
    ll value = -1;
    std::set<ll> right, seen;
    REP(i, N) {
        while (index < N) {
            if (seen.find(I[index]) == seen.end())
                break;
            value = I[index];
            right.insert(I[index]);
            index++;
        }
        if (value >= 0) {
            if (right.find(value) != right.end()) {
                ans[value].second = P[i];
            } else {
                ans[value].first = P[i];
            }
        }
        value = P[i];
        seen.insert(value);
    }

    vector<Vertex> V(N);
    REP(i, N) {
        V[i].left = ans[i].first;
        V[i].right = ans[i].second;
    }

    if (!check(V)) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, N) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    return 0;
}