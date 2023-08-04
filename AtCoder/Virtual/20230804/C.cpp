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

bool check(const vector<Vertex> &V, const vector<pll> &D, const string &S) {
    ll N = S.size();
    {
        bool e = false;
        REP(i, N) {
            if (S[i] == '1') {
                e = true;
            }
        }
        if (!e) {
            return false;
        }
    }

    REP(i, D.size()) {
        bool e = false;
        vector<bool> seen(N, false);
        queue<pll> q;
        q.push(pll(D[i].first, 0));
        seen[D[i].first] = true;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (t.second == D[i].second && S[t.first] == '1') {
                e = true;
                break;
            }
            for (auto n: V[t.first].node) {
                if (seen[n])
                    continue;
                seen[n] = true;
                q.push(pll(n, t.second + 1));
            }
        }
        if (!e) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    string ans = "";
    REP(i, N) {
        ans.push_back('1');
    }
    ll K;
    cin >> K;
    vector<pll> D(K);
    REP(i, K) {
        cin >> D[i].first >> D[i].second;
        D[i].first--;
    }

    REP(i, D.size()) {
        vector<bool> seen(N, false);
        queue<pll> q;
        q.push(pll(D[i].first, 0));
        seen[D[i].first] = true;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (t.second >= D[i].second) {
                continue;
            }
            ans[t.first] = '0';
            for (auto n: V[t.first].node) {
                if (seen[n])
                    continue;
                seen[n] = true;
                q.push(pll(n, t.second + 1));
            }
        }
    }

    if (check(V, D, ans)) {
        cout << "Yes" << endl;
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}