#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

int main() {
    string S, T;
    cin >> S >> T;
    ll N = S.length();

    vector<vector<ll>> in(30), out(30);
    bool exist = true;
    REP(i, N) {
        ll from = S[i] - 'a';
        ll to = T[i] - 'a';
        in[from].push_back(to);
        out[to].push_back(from);
    }

    REP(i, 30) {
        sort(in[i].begin(), in[i].end());
        in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
        sort(out[i].begin(), out[i].end());
        out[i].erase(unique(out[i].begin(), out[i].end()), out[i].end());

        if (in[i].size() >= 2 || out[i].size() >= 2)exist = false;
    }

    if (exist)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}