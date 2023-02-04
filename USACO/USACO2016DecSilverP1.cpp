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

vector<int> bales;
int N, Q;

int TTOF (int lo, int hi, function<bool(int)> f) { // finds the last T in a function that goes from false to true once
    while (lo < hi) {
        int mid = lo + (hi - lo + 1)/2; // if we search and round down, we infinite loop on lo = n, hi = n + 1 (assuming they are both T's')
        //cout << lo << " " << mid << " " << hi << "\n";
        if (f(mid)) {
            lo = mid; // can't rule out a T just yet
        } else {
            hi = mid - 1; // but we cna rule out an F
        }
    }
    // Assume lo = hi, check an edge case where f(x) is always false.
    if (!f(lo)) {
        return -1;
    }
    return lo;
}

int FTOT (int lo, int hi, function<bool(int)> f) { // finds the FIRST T!
    while (lo < hi) {
        int mid = lo + (hi - lo)/2; // if we search and round down, we infinite loop on lo = n, hi = n + 1 (assuming they are both F)
        //cout << lo << " " << mid << " " << hi << "\n";
        if (!f(mid)) {
            lo = mid+1; // can't rule out an F'
        } else {
            hi = mid; // can't rule out a T
        }
    }
    if (!f(lo)) {
        return -1;
    }
    return lo;
}

int main() {
    setIO("haybales");
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        bales.pb(a);
    }
    sort(vrange(bales));
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        /*
        lIndex: find the first haybale >= a, monotonic function
        rIndex: Find the last haybale <= b, also monotonic
        */
        int lIndex = FTOT(0, N-1, [&a] (int x) {return bales[x] >= a;} );  // modified FTOT
        int rIndex = TTOF(0, N-1, [&b] (int x) {return bales[x] <= b;} );
        if (lIndex == -1) {
            cout << 0 << "\n";
        } else {
            if (rIndex == -1) {
                cout << 0 << "\n";
            } else {
                cout << rIndex - lIndex + 1 << "\n";
            }
        }
        //cout << "LR: " << lIndex << " " << rIndex << "\n";
    }
}
