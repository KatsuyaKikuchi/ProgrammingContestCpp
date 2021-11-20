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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N >> S;

    std::map<string, std::map<string, ll>> mp;

    REP(bit, pow(2LL, N)) {
        string rs = "", bs = "";
        REP(i, N) {
            if ((bit >> i) & 1)
                rs.push_back(S[i]);
            else
                bs.push_back(S[i]);
        }
        mp[rs][bs]++;
    }

    ll ans = 0;

    reverse(S.begin(), S.end());
    REP(bit, pow(2LL, N)) {
        string rs = "", bs = "";
        REP(i, N) {
            if ((bit >> i) & 1)
                rs.push_back(S[i]);
            else
                bs.push_back(S[i]);
        }
        auto it0 = mp.find(bs);
        if (it0 == mp.end())
            continue;
        auto it1 = it0->second.find(rs);
        if (it1 == it0->second.end())
            continue;
        ans += it1->second;
    }

    cout << ans << endl;
    return 0;
}