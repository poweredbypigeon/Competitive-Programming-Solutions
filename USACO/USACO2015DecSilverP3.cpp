#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ull> vull;
typedef vector<vector<ull>> vdull;
typedef unsigned int ui;
typedef pair<int, int> pii;
typedef pair<ull, ull> pull;
typedef double db;
typedef pair<db, db> pdb;
typedef long double ld;

#define pf push_front
#define pb push_back
#define sz(x) (int) x.size()
#define vrange(x) x.begin(), x.end()
#define f first
#define s second

const int MOD = 1e9 + 7;
const ull INF = 1e18;
const int OTHER_MOD = 998244353;
const int BIG_INTEGER = 2147483647;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("bcount");
    vector<int> prefH = {0};
    vector<int> prefG = {0};
    vector<int> prefJ = {0};
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            prefH.pb(prefH[i] + 1);
            prefG.pb(prefG[i]);
            prefJ.pb(prefJ[i]);
        } else if (a == 2) {
            prefH.pb(prefH[i]);
            prefG.pb(prefG[i] + 1);
            prefJ.pb(prefJ[i]);
        } else if (a == 3) {
            prefH.pb(prefH[i]);
            prefG.pb(prefG[i]);
            prefJ.pb(prefJ[i] + 1);
        }
    }
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << prefH[b] - prefH[a-1] << " " << prefG[b] - prefG[a-1] << " " << prefJ[b] - prefJ[a-1] << "\n";
    }
}
/*

SOLUTION:

Assemble three different prefix sums for Holsteins, Guernseys, and Jerseys

*/
