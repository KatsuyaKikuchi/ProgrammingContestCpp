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

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll MAX = 1000005;
    vector<ll> P(K), VP(K);
    REP(i, K) {
        P[i] = i + 1;
        VP[i] = std::max(N - i, 1LL);
    }

    vector<bool> isPrime(MAX, true);
    vector<ll> C;
    FOR(i, MAX, 2) {
        if (!isPrime[i])
            continue;
        for (ll j = i + i; j < MAX; j += i) {
            isPrime[j] = false;
        }
        ll index = C.size();
        C.push_back(0);
        for (ll j = i; j < P.size() + 1; j += i) {
            while (P[j - 1] % i == 0) {
                C[index]--;
                P[j - 1] /= i;
            }
        }

        ll s = (N / i) * i;
        for (ll j = N - s; j < VP.size(); j += i) {
            while (VP[j] % i == 0) {
                C[index]++;
                VP[j] /= i;
            }
        }
    }
    std::map<ll, ll> indexMap;
    REP(i, K) {
        if (VP[i] > 1) {
            ll index;
            auto it = indexMap.find(VP[i]);
            if (it == indexMap.end()) {
                index = C.size();
                C.push_back(0);
                indexMap[VP[i]] = index;
            } else {
                index = it->second;
            }
            C[index]++;
        }
        if (P[i] > 1) {
            ll index;
            auto it = indexMap.find(P[i]);
            if (it == indexMap.end()) {
                index = C.size();
                C.push_back(0);
                indexMap[P[i]] = index;
            } else {
                index = it->second;
            }
            C[index]--;
        }
    }
    ll ans = 1;
    REP(i, C.size()) {
        ans = (ans * (C[i] + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}