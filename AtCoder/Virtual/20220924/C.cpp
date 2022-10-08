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

ll N, M;
bool A[100][100];
bool B[100][100];

bool check(const vector<ll> &V) {
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (!A[i][j])
                continue;
            ll a = V[i], b = V[j];
            if (!B[a][b])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    memset(A, false, sizeof(A));
    memset(B, false, sizeof(B));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = A[b][a] = true;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        B[a][b] = B[b][a] = true;
    }
    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    do {
        if (check(v)) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "No" << endl;
    return 0;
}