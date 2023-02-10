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


void printArray(int* arr, size_t size) { // only for arrays, 1st arg is a pointer.
    for (int i = 0; i < size; ++i) {
        cout << *arr++ << " ";
    }
    cout << "\n";
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    // have an array showing which are reachable from which
    // e.g. for 1970, if A and B = 1000, at index 3 you would have 990 and 1010 in there.
    vector<vector<int>> reachable = {{}};
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int m;
        cin >> m;
        motels.pb(m);
    }
    N += 14; // N is now length of the array
    sort(motels.begin(), motels.end());
    for (int i = 1; i < N; ++i) {
        vector<int> inputReachable = {}; // all the models reachable by index i
        for (int j = 0; j < i; ++j) {
            // cout << "DISTANCE: " << motels[i] << " " << motels[j] << "\n";
            int distance = motels[i] - motels[j];
            if (B >= distance && distance >= A) {
                inputReachable.pb(j);
            }
        }
        reachable.pb(inputReachable);
    }
    long long dp[N];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int motel : reachable[i]) {
            dp[i] += dp[motel];
        }
    }
    cout << dp[N-1] << "\n";
    return 0;
}
