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
    setIO("diamond");
    int N, K;
    cin >> N >> K;
    int diamondArr[N];
    int diamondArrShift[N];
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        diamondArr[i] = a;
        diamondArrShift[i] = a+K;
    }
    sort(diamondArr, diamondArr + N);
    sort(diamondArrShift, diamondArrShift + N); // not really optimal.
    /* for (int i = 0; i < N; ++i) {
        cout << diamondArr[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; ++i) {
        cout << diamondArrShift[i] << " ";
    }
    cout << "\n"; */
    vector<pair<int, int>> diamondCase;
    int ptr1 = 0;
    int ptr2 = 0;
    while ((ptr1 != (N)) && (ptr2 != (N))) { // do not go out of bounds, sort out bugs later if ptr1 is (N-1 ptr1 should be higher than ptr2 to be honest
        // cout << ptr1 << " " << ptr2 << " " << diamondArr[ptr1] << " " << diamondArrShift[ptr2] << "\n";
        if (diamondArr[ptr1] <= diamondArrShift[ptr2]) {
            if (ptr1 == (N-1)) {
                ++ptr2;
                diamondCase.pb({ptr1-ptr2+2, -1}); // theoretically should be (ptr1+1)-ptr2 + 1 but ptr+1 doesn't exist don't know why +1 is there, just know that it works
            } else {
                ++ptr1;
            }
        } else {
            ++ptr2;
            diamondCase.pb({ptr1-ptr2+1, ptr1});
        }
    }
    int maxDiamonds = 0;
    int maxDiamondsWithinRange[N];
    maxDiamondsWithinRange[N-1] = diamondCase[N-1].first;
    for (int i = (N-2); i >= 0; --i) {
        maxDiamondsWithinRange[i] = max(maxDiamondsWithinRange[i+1], diamondCase[i].first);
    }
    for (int i = 0; i < N; ++i) {
        if (diamondCase[i].second != -1) {
            maxDiamonds = max(maxDiamonds, diamondCase[i].first + maxDiamondsWithinRange[diamondCase[i].second]);
        } else {
            maxDiamonds = max(maxDiamonds, diamondCase[i].first);
        }
    }
    cout << maxDiamonds << "\n";

    return 0;
}

// need to find a better solution to this
