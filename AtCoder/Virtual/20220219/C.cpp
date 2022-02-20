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

bool check(ll N, ll n) {
    if (n == 1)
        return false;
    while (N % n == 0) {
        N /= n;
    }
    return N % n == 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll n = 1;
    set<ll> st;
    while (n * n <= N) {
        if (N % n == 0) {
            ll t = N / n;
            if (check(N, n))st.insert(n);
            if (check(N, t))st.insert(t);
        }
        n++;
    }
    N--;
    n = 1;
    while (n * n <= N) {
        if (N % n == 0) {
            ll t = N / n;
            st.insert(t);
            st.insert(n);
        }
        n++;
    }
    cout << st.size() - 1 << endl;
    return 0;
}