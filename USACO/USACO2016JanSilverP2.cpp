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
    setIO("div7");
    int N;
    cin >> N;
    vector<int> pref = {0};
    vector<int> lowest = {-1, -1, -1, -1, -1, -1, -1}; // each representing 0-6
    vector<int> highest = {-1, -1, -1, -1, -1, -1, -1}; // each representing 0-6
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        int nuVal = (pref[i] + a) % 7;
        if (lowest[nuVal] == -1) {
            lowest[nuVal] = i; // i cannot be -1
        } else {
            highest[nuVal] = i;
        }
        pref.pb(nuVal);
    }
    /*for (int i = 0; i <= N; ++i) {
        cout << pref[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 7; ++i) {
        cout << lowest[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 7; ++i) {
        cout << highest[i] << " ";
    }
    cout << "\n";*/
    int groupLength = 0;
    for (int i = 0; i < 7; ++i) {
        if (lowest[i] != -1 && highest[i] != -1) {
            groupLength = max(groupLength, highest[i] - lowest[i]);
        }
    }
    cout << groupLength;
}
// {0, 3, 1, 2, 1, 3, 3, 6}
// create a prefix sum mod 7
/* index 1: 0 + 1, index 2: 0 + 1 + 2, etc.
keep track of the lowest and highest 0-6 and then subtract highest - lowest for each and find the max.

What if there's no value of a particular number, or only 1 value???

*/
