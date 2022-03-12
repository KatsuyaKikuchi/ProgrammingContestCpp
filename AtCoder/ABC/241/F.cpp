#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<ll> node;
    pll g;
};

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> H >> W >> N;
    pll s, g;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    vector<pll> A(N);
    vector<ll> X, Y;

    vector<Vertex> V;
    std::map<pll, ll> idx;
    std::map<pll, ll> ice;

    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
        Y.push_back(A[i].second);
        ice[A[i]] = i;
    }
    {
        idx[s] = V.size();
        Vertex v;
        v.g = s;
        V.emplace_back(v);
        X.push_back(s.first);
        Y.push_back(s.second);
    }
    REP(i, N) {
        REP(j, 4) {
            ll nx = dx[j] + A[i].first, ny = dy[j] + A[i].second;
            if (nx <= 0 || ny <= 0 || nx > H || ny > W)
                continue;
            pll tt(nx, ny);
            if (ice.find(tt) != ice.end())
                continue;
            X.push_back(nx);
            Y.push_back(ny);
            if (idx.count(tt) != 0)
                continue;
            idx[tt] = V.size();
            Vertex v;
            v.g = tt;
            V.emplace_back(v);
        }
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    vector<vector<pll>> GX(X.size()), GY(Y.size()), IX(X.size()), IY(Y.size());

    REP(i, N) {
        ll xi = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
        ll yi = lower_bound(Y.begin(), Y.end(), A[i].second) - Y.begin();
        IX[xi].push_back(pll(A[i].second, i));
        IY[yi].push_back(pll(A[i].first, i));
    }
    REP(i, V.size()) {
        pll t = V[i].g;
        ll nxi = lower_bound(X.begin(), X.end(), t.first) - X.begin();
        ll nyi = lower_bound(Y.begin(), Y.end(), t.second) - Y.begin();
        GX[nxi].push_back(pll(t.second, i));
        GY[nyi].push_back(pll(t.first, i));
    }

    REP(i, X.size()) {
        sort(GX[i].begin(), GX[i].end());
        sort(IX[i].begin(), IX[i].end());

        ll iceIndex = 0;
        for (auto &x: GX[i]) {
            while (iceIndex < IX[i].size() && IX[i][iceIndex].first < x.first) {
                iceIndex++;
            }
            ll vi = x.second;
            if (iceIndex - 1 >= 0) {
                ll ii = IX[i][iceIndex - 1].second;
                pll stop(X[i], A[ii].second + 1);

                auto it = idx.find(stop);
                if (it != idx.end() && it->second != vi) {
                    V[vi].node.push_back(it->second);
                }
            }
            if (iceIndex < IX[i].size()) {
                ll ii = IX[i][iceIndex].second;
                pll stop(X[i], A[ii].second - 1);
                auto it = idx.find(stop);
                if (it != idx.end() && it->second != vi) {
                    V[vi].node.push_back(it->second);
                }
            }
        }
    }
    REP(i, Y.size()) {
        sort(GY[i].begin(), GY[i].end());
        sort(IY[i].begin(), IY[i].end());

        ll iceIndex = 0;
        for (auto &y: GY[i]) {
            while (iceIndex < IY[i].size() && IY[i][iceIndex].first < y.first) {
                iceIndex++;
            }
            ll vi = y.second;
            if (iceIndex - 1 >= 0) {
                ll ii = IY[i][iceIndex - 1].second;
                pll stop(A[ii].first + 1, Y[i]);

                auto it = idx.find(stop);
                if (it != idx.end() && it->second != vi) {
                    V[vi].node.push_back(it->second);
                }
            }
            if (iceIndex < IY[i].size()) {
                ll ii = IY[i][iceIndex].second;
                pll stop(A[ii].first - 1, Y[i]);
                auto it = idx.find(stop);
                if (it != idx.end() && it->second != vi) {
                    V[vi].node.push_back(it->second);
                }
            }
        }
    }


    if (idx.find(g) == idx.end()) {
        cout << -1 << endl;
        return 0;
    }

    ll goal = idx[g];
    vector<ll> D(V.size(), INF);
    ll start = idx[s];

    D[start] = 0;

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });

    q.push(pll(0, start));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (D[t.second] < t.first)
            continue;
        ll cost = D[t.second] + 1;
        for (auto n: V[t.second].node) {
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(pll(cost, n));
        }
    }

    ll ans = D[goal];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;


    return 0;
}