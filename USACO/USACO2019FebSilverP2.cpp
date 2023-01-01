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

int arr[1002][1002];

int main() {
    setIO("paintbarn");
    memset(arr, 0, sizeof(arr));
    int area = 0;
    int N, K;
    cin >> N >> K;
    // handle updates
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1]++;
        arr[x2][y1]--;
        arr[x1][y2]--;
        arr[x2][y2]++; // don't overwrite the values
    }
    /*for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    // prefix sum
    for (int i = 1; i <= 1001; ++i) {
        for (int j = 0; j <= 1001; ++j) {
            arr[i][j] += arr[i-1][j];
        }
    }
    /*for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    for (int j = 1; j <= 1001; ++j) {
        for (int i = 0; i <= 1001; ++i) {
            arr[i][j] += arr[i][j-1];
        }
    }
    /*for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    // count
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            if (arr[i][j] == K) {
                ++area;
            }
        }
    }
    cout << area << endl;
    return 0;
}

