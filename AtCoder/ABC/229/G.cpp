#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

string S;
ll K, N;
vector<ll> Y;

bool check(ll m) {
    ll mn = INF;
    ll s = 0, e = m - 1;
    ll mid = s + (m / 2);
    ll sum = 0;
    for (ll i = mid - 1; i >= s; --i) {
        sum += std::max(0LL, (Y[mid] - 1) - Y[i] - (mid - 1 - i));
    }
    for (ll i = mid + 1; i <= e; ++i) {
        sum += std::max(0LL, Y[i] - (Y[mid] + 1) - (i - (mid + 1)));
    }
    ll left = mid - s;
    ll right = e - mid;
    while (e < Y.size()) {
        mn = std::min(mn, sum);
        mid++;
        if (mid >= Y.size())
            break;
        sum -= (Y[mid - 1] - Y[s] - 1 - (left - 1));
        sum += (Y[mid] - Y[mid - 1] - 1) * (left - 1);
        sum -= (Y[mid] - Y[mid - 1] - 1) * (right - 1);
        e++;
        if (e >= Y.size())
            break;
        sum += (Y[e] - Y[mid] - 1 - (right - 1));
        s++;
    }
    return mn <= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    cin >> K;
    N = S.length();
    REP(i, N) {
        if (S[i] == 'Y')
            Y.push_back(i);
    }

    ll ok = 0, ng = Y.size() + 1;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}