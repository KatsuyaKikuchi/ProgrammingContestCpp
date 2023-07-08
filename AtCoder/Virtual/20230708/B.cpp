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

ll solve(vector<ll> &A, string &S, vector<ll> c) {
    ll ret = 0;
    std::map<char, ll> mp;
    mp['M'] = c[0];
    mp['E'] = c[1];
    mp['X'] = c[2];

    ll M = 0, E = 0, X = 0;
    ll N = A.size();
    REP(i, N) {
        if (A[i] != mp[S[i]])
            continue;
        if (S[i] == 'M') {
            M++;
        } else if (S[i] == 'E') {
            E += M;
        } else {
            ret += E;
        }
    }
    return ret;
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
    string S;
    cin >> S;

    ll ans = 0;
    {
        vector<ll> c = {0, 0, 0};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {2, 0, 0};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {0, 2, 0};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {0, 0, 2};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {2, 2, 0};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {0, 2, 2};
        ans += solve(A, S, c) * 1;
    }
    {
        vector<ll> c = {2, 0, 2};
        ans += solve(A, S, c) * 1;
    }

    {
        vector<ll> c = {1, 0, 0};
        ans += solve(A, S, c) * 2;
    }
    {
        vector<ll> c = {0, 1, 0};
        ans += solve(A, S, c) * 2;
    }
    {
        vector<ll> c = {0, 0, 1};
        ans += solve(A, S, c) * 2;
    }
    {
        vector<ll> c = {1, 1, 0};
        ans += solve(A, S, c) * 2;
    }
    {
        vector<ll> c = {1, 0, 1};
        ans += solve(A, S, c) * 2;
    }
    {
        vector<ll> c = {0, 1, 1};
        ans += solve(A, S, c) * 2;
    }

    {
        vector<ll> c = {0, 1, 2};
        ans += solve(A, S, c) * 3;
    }
    {
        vector<ll> c = {0, 2, 1};
        ans += solve(A, S, c) * 3;
    }
    {
        vector<ll> c = {1, 0, 2};
        ans += solve(A, S, c) * 3;
    }
    {
        vector<ll> c = {1, 2, 0};
        ans += solve(A, S, c) * 3;
    }
    {
        vector<ll> c = {2, 0, 1};
        ans += solve(A, S, c) * 3;
    }
    {
        vector<ll> c = {2, 1, 0};
        ans += solve(A, S, c) * 3;
    }

    cout << ans << endl;
    return 0;
}