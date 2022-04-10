#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll MAX = 1000000000;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

void solve() {
    ll N;
    cin >> N;
    vector<ll> V, v;
    std::set<ll> st;
    ll p = 1;
    while (p <= MAX) {
        V.push_back(p);
        st.insert(p);
        v.push_back(p);

        p *= 2;
    }
    ll n = MAX;
    while (V.size() < N) {
        while (st.find(n) != st.end()) {
            n--;
        }
        V.push_back(n);
        st.insert(n);
    }
    REP(i, N) {
        cout << V[i] << " ";
    }
    cout << endl;
    REP(i, N) {
        ll a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end(), greater<ll>());
    ll sum = 0;
    REP(i, V.size()) {
        sum += V[i];
    }
    sum /= 2;

    vector<ll> ret;
    ll index = 0;
    while (sum >= p) {
        ll a = V[index];
        index++;
        if (std::find(v.begin(), v.end(), a) != v.end()) {
            continue;
        }
        if (sum >= a) {
            sum -= a;
            ret.push_back(a);
        }
    }

    p = 1;
    while (sum > 0) {
        if ((sum & 1) == 1)
            ret.push_back(p);
        sum /= 2;
        p *= 2;
    }

    sort(ret.begin(), ret.end());
    REP(i, ret.size()) {
        cout << ret[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        solve();
    }
    return 0;
}