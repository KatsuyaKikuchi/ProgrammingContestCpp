#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S;

bool check(vector<ll> &t) {
    ll N = t.size() - 1;
    REP(i, N) {
        ll a = t[i];
        ll b = t[i + 1];
        if (S[i] == '<' && a >= b)
            return false;
        if (S[i] == '>' && a <= b)
            return false;
    }
    REP(i, N + 1) {
        if (t[i] < 0)
            return false;
    }
    return true;
}

int main() {
    ll N;
    cin >> N;
    cin >> S;
    vector<ll> A(N + 1);
    REP(i, N + 1) {
        cin >> A[i];
    }
    vector<ll> B(N + 1);
    REP(i, N + 1) {
        ll count = 0;
        for (ll left = i - 1; left >= 0; --left) {
            if (S[left] == '>')
                break;
            count = std::max(count, i - left);
        }
        for (ll right = i; right < N; ++right) {
            if (S[right] == '<')
                break;
            count = std::max(count, right - i + 1);
        }
        B[i] = count;
    }


    for (ll n = 10000; n >= 1; --n) {
        vector<ll> t(N + 1), b(N + 1);
        REP(i, N + 1) {
            t[i] = A[i] / n;
            b[i] = A[i] % n;
        }
        if (!check(t))
            continue;
        vector<ll> c(N + 1);
        REP(i, N + 1) {
            c[i] = t[i] + b[i];
        }
        if (!check(c))
            continue;

        cout << n << endl;
        REP(_, n) {
            vector<ll> ans(N + 1);
            REP(i, N + 1) {
                ans[i] = t[i];
                if (b[i] > 0)
                    ans[i]++;
                b[i]--;
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        break;
    }
    return 0;
}