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
    int M, N;
    cin >> M >> N;
    vector<pair<int, string>> id = {};
    vector<int> minTimeArr = {}; // keeps track of how many ppl are each group too. uint is min time form first i ppl
    vvi minTimeGroupArr; // corresponds with minTimeArr: the array that got things started
    for (int i = 0; i < N; ++i) {
        string a;
        int b;
        cin >> a;
        cin >> b;
        id.pb({b, a});
    }
    int maxGroupTime = 0;
    for (int j = 0; j < M; ++j) {
        maxGroupTime = max(maxGroupTime, id[j].first);
        minTimeArr.pb(maxGroupTime);
        minTimeGroupArr.pb({j+1});
    }

    for (int i = M; i < N; ++i) {
        int cumulativeGroupTime = 0; // used to save time calculating
        int minTime = 1000000;
        vector<int> minTimeGroup = {};
        for (int j = 1; j <= M; ++j) { // new group is of size j
            if (i-j >= 0) {
                int newPossTime = minTimeArr[i-j] + max(cumulativeGroupTime, id[i-j+1].first); // group size j
                if (minTime > newPossTime) {
                    minTime = newPossTime;
                    minTimeGroup = minTimeGroupArr[i-j];
                    minTimeGroup.pb(j);
                }
                cumulativeGroupTime = max(cumulativeGroupTime, id[i-j+1].first);
                // cout << i << " " << j << " " << cumulativeGroupTime << " " << newPossTime << "\n";
            }
        }
        minTimeArr.pb(minTime);
        minTimeGroupArr.pb(minTimeGroup);
    }
    cout << "Total Time: " << minTimeArr[N-1] << "\n";
    vi minTimeFinalGroup = minTimeGroupArr[N-1];
    int counter = 0;
    for (int groupSize : minTimeFinalGroup) {
        for (int i = 0; i < groupSize; ++i) {
            cout << id[counter+i].second << " ";
        }
        counter += groupSize;
        cout << "\n";
    }
    return 0;
}

/*
2
5
alice
1
bob
5
charlie
5
dobson
3
eric
3


Save the minimum amount of time it would take for the first i people, and when going through the min time for i+1 people,
loop through the minimum time for i, i-1, i-2..., i-M+1 an add the maximum time it would take for a new group (you are looping through
                                                                                                               groups of size 1, 2,..., M)
You also need to store the sizes of each group so you can print them out at the end. Really harder than it looks.
*/
