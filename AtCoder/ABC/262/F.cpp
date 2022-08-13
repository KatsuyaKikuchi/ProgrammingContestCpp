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

struct Data {
    ll value;
    ll index;
    bool back;
};

vector<ll> solve(const vector<ll> &A, const vector<ll> &B) {
    if (B.size() == 0)
        return A;
    REP(i, std::min(A.size(), B.size())) {
        if (A[i] < B[i])
            return A;
        else if (A[i] > B[i])
            return B;
    }

    if (A.size() < B.size())
        return A;
    return B;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    REP(i, N) {
        cin >> P[i];
    }

    vector<ll> A, B;
    {
        // frontから掘っていく
        ll minIndex = 0;
        REP(i, K) {
            if (P[minIndex] > P[i + 1])
                minIndex = i + 1;
        }
        vector<bool> C(N, false);
        vector<bool> E(N, false);
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
        FOR(i, N, minIndex) {
            q.push(pll(P[i], i));
        }
        ll count = K - minIndex;
        std::set<ll> indices;
        indices.insert(minIndex - 1);
        indices.insert(INF);

        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q2([](pll a, pll b) { return a.first < b.first; });

        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (E[t.second])
                continue;
            auto it = indices.lower_bound(t.second);
            it--;
            ll diff = t.second - (*it) - 1;
            if (diff <= count) {
                C[t.second] = true;
                FOR(i, t.second, (*it) + 1) {
                    E[i] = true;
                }
                count -= diff;
                indices.insert(t.second);
            } else {
                q2.push(t);
            }
        }

        while (count > 0) {
            pll t = q2.top();
            q2.pop();
            count--;
            E[t.second] = true;
        }

        FOR(i, N, minIndex) {
            if (!E[i] || C[i]) {
                A.push_back(P[i]);
            }
        }
    }

    if (K > 0) {
        // backから掘っていく
        ll minIndex = N;
        REP(i, K - 1) {
            if (minIndex == N || P[minIndex] > P[N - 1 - i])
                minIndex = N - 1 - i;
        }
        vector<bool> C(N, false);
        vector<bool> E(N, false);
        priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q(
                [](Data a, Data b) { return a.value > b.value; });
        FOR(i, N, minIndex) {
            q.push(Data{P[i], i, true});
        }
        REP(i, minIndex) {
            q.push(Data{P[i], i, false});
        }
        ll count = K - 1 - (N - minIndex - 1);
        std::set<ll> indices;
        indices.insert(-1);
        indices.insert(minIndex);
        indices.insert(INF);

        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q2([](pll a, pll b) { return a.first < b.first; });

        while (!q.empty()) {
            Data t = q.top();
            q.pop();
            if (E[t.index])
                continue;
            auto it = indices.upper_bound(t.index);
            it--;
            ll diff = 0;
            if (!t.back) {
                diff = t.index - (*it) - 1;
            }
            if (diff <= count) {
                C[t.index] = true;
                FOR(i, t.index, (*it) + 1) {
                    E[i] = true;
                }
                count -= diff;
                indices.insert(t.index);
            } else {
                q2.push(pll(t.value, t.index));
            }
        }

        while (count > 0) {
            pll t = q2.top();
            q2.pop();
            count--;
            E[t.second] = true;
        }

        FOR(i, N, minIndex) {
            if (!E[i] || C[i]) {
                B.push_back(P[i]);
            }
        }
        REP(i, minIndex) {
            if (!E[i] || C[i]) {
                B.push_back(P[i]);
            }
        }
    }

    auto ans = solve(A, B);

    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}