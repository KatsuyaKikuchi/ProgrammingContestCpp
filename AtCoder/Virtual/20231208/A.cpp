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
    pll pair;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    vector<pll> X(N), Y(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X[i] = pll(A[i].first, i);
        Y[i] = pll(A[i].second, i);
    }
    sort(X.begin(), X.end(), [](pll a, pll b) { return a.first > b.first; });
    sort(Y.begin(), Y.end(), [](pll a, pll b) { return a.first > b.first; });

    vector<Data> ans;
    ans.push_back(Data{X[0].first - X[N - 1].first,
                       pll(std::min(X[0].second, X[N - 1].second), std::max(X[0].second, X[N - 1].second))});
    ans.push_back(Data{X[1].first - X[N - 1].first,
                       pll(std::min(X[1].second, X[N - 1].second), std::max(X[1].second, X[N - 1].second))});
    ans.push_back(Data{X[0].first - X[N - 2].first,
                       pll(std::min(X[0].second, X[N - 2].second), std::max(X[0].second, X[N - 2].second))});
    ans.push_back(Data{X[1].first - X[N - 2].first,
                       pll(std::min(X[1].second, X[N - 2].second), std::max(X[1].second, X[N - 2].second))});
    ans.push_back(Data{Y[0].first - Y[N - 1].first,
                       pll(std::min(Y[0].second, Y[N - 1].second), std::max(Y[0].second, Y[N - 1].second))});
    ans.push_back(Data{Y[1].first - Y[N - 1].first,
                       pll(std::min(Y[1].second, Y[N - 1].second), std::max(Y[1].second, Y[N - 1].second))});
    ans.push_back(Data{Y[0].first - Y[N - 2].first,
                       pll(std::min(Y[0].second, Y[N - 2].second), std::max(Y[0].second, Y[N - 2].second))});
    ans.push_back(Data{Y[1].first - Y[N - 2].first,
                       pll(std::min(Y[1].second, Y[N - 2].second), std::max(Y[1].second, Y[N - 2].second))});

    sort(ans.begin(), ans.end(), [](Data a, Data b) { return a.value > b.value; });

    FOR(i, ans.size(), 1) {
        if (ans[i].pair != ans[0].pair) {
            cout << ans[i].value << endl;
            break;
        }
    }
    return 0;
}