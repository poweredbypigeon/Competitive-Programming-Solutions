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

int N, K;
vector<int> bales = {};

bool pos(int R) {
    int cows = 1;
    int firstIndex = bales[0]; // the position of the first cow destroyed by the bale.
    // what we're doing is once we spot the first index, we shoot a cow R units to the right of the index, and getting rid of everything 2R units to the right of the first index.
    for (int i = 1; i < N; ++i) {
        int cowPos = bales[i];
        if (cowPos - firstIndex > 2*R) {
            firstIndex = bales[i];
            ++cows;
        }
    }
    // cout << "COWS NEEDED: " << cows << "\n";
    return (cows <= K);
    // given a certain R, can you destroy everything in K or less?
}

int bSearch(int low, int high, function<bool(int)> f) { // trying to find the first true value

    while (low < high) {
        int mid = low + (high - low)/2;
        // cout << low << " " << mid << " " << high << "\n";
        if (f(mid)) {
            high = mid; // keep the true
        } else {
            low = mid + 1; // dump the false
        }
    }
    return low;
}

int main() {
    [setIO("angry");

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        bales.pb(a);
    }
    sort(bales.begin(), bales.end());
    cout << bSearch(0, 1e9, pos);

    return 0;
}
