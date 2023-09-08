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

vector<pll> rangeP(ll B, ll C) {
    vector<pll> ret;
    ret.push_back(pll(B - C / 2, B));
    if (C >= 1)
        ret.push_back(pll(-B - (C - 1) / 2, -B));
    if (C >= 2) {
        ret.push_back(pll(B, B + (C - 2) / 2));
    }
    if (B == 0 && C >= 1) {
        ret.push_back(pll(B, B + (C - 1) / 2));
    }
    return ret;
}

vector<pll> rangeM(ll B, ll C) {
    vector<pll> ret;
    ret.push_back(pll(B - C / 2, B));
    if (C >= 1)
        ret.push_back(pll(-B, -B + (C - 1) / 2));
    if (C >= 2) {
        ret.push_back(pll(B, B + (C - 2) / 2));
    }
    if (B == 0 && C >= 1) {
        ret.push_back(pll(B, B + (C - 1) / 2));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll B, C;
    cin >> B >> C;
    vector<pll> R;
    if (B >= 0) {
        {
            auto n = rangeP(B, C);
            for (auto x: n) {
                R.push_back(x);
            }
        }
        {
            auto n = rangeM(-B, C - 1);
            for (auto x: n) {
                R.push_back(x);
            }
        }
    } else {
        {
            auto n = rangeP(-B, C - 1);
            for (auto x: n) {
                R.push_back(x);
            }
        }
        {
            auto n = rangeM(B, C);
            for (auto x: n) {
                R.push_back(x);
            }
        }
    }

    sort(R.begin(), R.end(), [](pll a, pll b) { return a.first < b.first; });
    REP(i, R.size() - 1) {
        if (R[i].second >= R[i + 1].first)
            R[i].second = R[i + 1].first - 1;
        //cout << "(" << R[i].first << "," << R[i].second << ")" << endl;
    }
    ll ans = 0;
    REP(i, R.size()) {
        ans += R[i].second - R[i].first + 1;
    }
    cout << ans << endl;

    return 0;
}