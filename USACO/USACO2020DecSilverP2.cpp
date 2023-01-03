nclude <bits/stdc++.h>

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

int arr[2501][2501]; // prefix array will need to be twice as big 2N+2, 2N+1 x 2N+1 plus a layer here.
// everything is 1 indexed, had to switch midway due to prefix sum issue

int main() {
    memset(arr, 0, sizeof(arr));
    int N;
    cin >> N;
    long long sols = N+1; // the empty subset and cow 1, 2, 3..., N always work
    vector<pair<int, int>> cows;
    vector<pair<int, int>> xs; // <x coord, number>
    vector<pair<int, int>> ys;
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        cows.pb({x, y});
        xs.pb({x, i});
        ys.pb({y, i});
    }
    // compression
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    for (auto iter = xs.begin(); iter != xs.end(); ++iter) {
        pii x = *iter;
        cows[x.second-1].first = (iter - xs.begin() + 1);
    }
    for (auto iter = ys.begin(); iter != ys.end(); ++iter) {
        pii y = *iter;
        cows[y.second-1].second = (iter - ys.begin() + 1);
    }

    /*for (auto iter = xs.begin(); iter != xs.end(); ++iter) {
        pii i = *iter;
        cout << i.first << " " << i.second << "\n";
    }
    cout << "\n";
    for (auto iter = ys.begin(); iter != ys.end(); ++iter) {
        pii i = *iter;
        cout << i.first << " " << i.second << "\n";
    }
    cout << "\n";
    */
    for (auto iter = cows.begin(); iter != cows.end(); ++iter) {
        pii i = *iter;
        arr[i.first][i.second] = 1;
        // cout << i.first << " " << i.second << "\n";
    }

    // prefix sum
    for (int i = 1; i <= 2500; ++i) {
        for (int j = 0; j <= 2500; ++j) {
            arr[i][j] += arr[i-1][j];
        }
    }
    for (int j = 1; j <= 2500; ++j) {
        for (int i = 0; i <= 2500; ++i) {
            arr[i][j] += arr[i][j-1];
        }
    }
    /*
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    // loop through pairs, hard to see observation
    for (int c1 = 0; c1 < N; ++c1) {
        for (int c2 = 0; c2 < N; ++c2) {
            if (c1 >= c2) {
                continue;
            } // we either don't want to count (c1 = c2), or don't want to double count (c1 > c2)
            pii cow1 = cows[c1];
            pii cow2 = cows[c2];
            int x1 = min(cow1.first, cow2.first);
            int x2 = max(cow1.first, cow2.first);
            int y1 = min(cow1.second, cow2.second);
            int y2 = max(cow1.second, cow2.second);
            // hardest part is prefix summing everything up
            int high = arr[x2][N] - arr[x2][y2] - arr[x1-1][N] + arr[x1-1][y2]; // 0 to 1 index
            int low = arr[x2][y1-1] - arr[x2][0] - arr[x1-1][y1-1] + arr[x1-1][0];
            sols += (high+1)*(low+1);

            /*high = arr[trComp.first][trComp.second] - arr[topright.first][topright.second];
            low = arr[bottomleft.first][bottomleft.second] - arr[blComp.first][blComp.second];
            sols += (high+1)*(low+1); // shouldn't go over 2B, max 2501*2501.*/
            //cout << c1 << " " << c2 << " " << high << " " << low << "\n"; // debug
        }
    }
    cout << sols << endl;
    return 0;
}
