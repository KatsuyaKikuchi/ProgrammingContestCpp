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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    std::map<char, ll> A, a;
    REP(i, N) {
        if ('A' <= S[i] && S[i] <= 'Z')A[S[i]]++;
        else a[S[i]]++;
    }

    bool e = A.size() > 0 && a.size() > 0;
    for (auto t: A) {
        if (t.second > 1)e = false;
    }
    for (auto t: a) {
        if (t.second > 1)e = false;
    }

    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}