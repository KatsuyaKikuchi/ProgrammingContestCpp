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
    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    REP(i, N) {
        A[i] = i + 1;
    }

    pll start, end;
    ll count = 0;
    REP(i, N) {
        ll c = N - i - 1;
        if (count + 1 <= L && L <= count + c) {
            start = pll(i, i + L - count);
        }
        if (count + 1 <= R && R <= count + c) {
            end = pll(i, i + R - count);
        }
        count += c;
    }

#if false
    cout << start.first << " " << start.second << endl;
    cout << end.first << " " << end.second << endl;
#endif

    if (start.first == end.first) {
        for (ll i = start.second; i <= end.second; ++i) {
            ll x = start.first;
            ll y = i;
            swap(A[x], A[y]);
        }
    } else {
        for (ll y = start.second; y < N; ++y) {
            ll x = start.first;
            swap(A[x], A[y]);
        }

#if false
        REP(i, N) {
            cout << A[i] << " ";
        }
        cout << endl;
#endif

        vector<ll> ans;

        for (ll i = 0; i <= start.first; ++i) {
            ans.push_back(A[i]);
        }
        for (ll x = start.first + 1; x < end.first; ++x) {
            ans.push_back(A[N - 1 - (x - start.first - 1)]);
#if false
            REP(i, ans.size()) {
                cout << ans[i] << " ";
            }
            cout << endl;
#endif
        }

        ll front = start.first + 1;
        while (ans.size() < N) {
            ans.push_back(A[front]);
            front++;
        }

        for (ll y = end.first; y <= end.second; ++y) {
            ll x = end.first;
            swap(ans[x], ans[y]);
        }

        REP(i, N) {
            A[i] = ans[i];
        }
    }

    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}