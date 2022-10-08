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
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<bool> Y(N + 5, false);
    {
        std::set<ll> st;
        ll sum = 0;
        st.insert(0);
        REP(i, N) {
            sum += A[i];
            ll p = sum - P;
            if (st.find(p) != st.end())
                Y[i] = true;
            st.insert(sum);
        }
    }

    vector<ll> Z;
    {
        std::set<ll> st;
        ll sum = 0;
        st.insert(0);
        REP(i, N) {
            sum += A[N - 1 - i];
            ll r = sum - R;
            if (st.find(r) != st.end())
                Z.push_back(N - 1 - i);
            st.insert(sum);
        }
    }
    sort(Z.begin(), Z.end());
    ll left = 0, right = 0;
    ll s = 0;
    ll z_index = 0;

    FOR(i, N, 1) {
        if (!Y[i - 1])
            continue;
        FOR(j, i, left) {
            s -= A[j];
        }
        left = i;
        while (z_index < Z.size()) {
            FOR(j, Z[z_index], right) {
                s += A[j];
            }
            right = Z[z_index];
            z_index++;
            if (s >= Q)
                break;
        }

        if (s == Q) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}