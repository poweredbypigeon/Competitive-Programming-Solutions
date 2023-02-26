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
    setIO("lifeguards");
    int totalTime = 0; // assuming no lifeguards are fired, the total time everyone is on
    vector<pii> values = {}; // index i contains event number i (event is a cow starting/leaving))
    int N;
    cin >> N;
    int removalTimes[N]; // stores time when only the cow at index i is supervising
    int arrived[N]; // this tracks if it's the 1st or 2nd time that we've progressed a lifegurad's event
    memset(removalTimes, 0, sizeof(removalTimes));
    memset(arrived, 0, sizeof(arrived));
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        values.pb({a, i});
        values.pb({b, i});
    }
    sort(values.begin(), values.end()); // should sort by the 1st element
    set<int> process = {};
    for (int i = 0; i < (2*N-1); ++i) { // goes to 2*N - 2 to avoid errors with totalTime, really the last entry is always removing the last lifeguard.
        int query = values[i].second;
        if (!arrived[query]) {
            arrived[query] = 1;
            process.insert(query);
        } else {
            process.erase(query);
        }
        // process the set, add the total time or removal time. For index i = 1, process interval 1 -> 2.
        int deltaTime = values[i+1].first - values[i].first;
        if (process.size() != 0) {
            totalTime += deltaTime;
        }
        if (process.size() == 1) {
            auto firstElement = process.begin();
            removalTimes[*firstElement] += deltaTime;
        }
    }
    int minTime = 1000000001; // minimum time to sacrifice by firing a lifeguard
    for (int i = 0; i < N; ++i) {
        if (minTime > removalTimes[i]) {
            minTime = removalTimes[i];
        }
    }
    cout << totalTime - minTime;
    return 0;
}

/*
good that the endpoints are distinct

*/
