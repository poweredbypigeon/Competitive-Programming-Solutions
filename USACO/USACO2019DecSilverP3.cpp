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

int N, M;

int videos = -1;

vector<bool> milkType = {false};
// stores what type of milk the cow at index i produces. true- Holstein, false- Guernsey

vvi adj = {{}}; // 1 indexed
vector<bool> visited = {true};
vector<int> componentOfCow = {0}; // which component the cow at index i is affiliated with
vector<bool> holstein = {false}; // whether the component at index i is holstein or not.

int componentNum = 1; // current component number, goes from 1 to 2 to 3, etc.

void dfs (int s) {
    if (visited[s]) {
        return;
    }
    visited[s] = true;
    // cout << "DFS: " << s << "\n";
    componentOfCow[s] = componentNum;
    for (auto u : adj[s]) {
        if (milkType[u] == milkType[s]) {
            dfs(u);
        }
    }
}


int main()
{
    setIO("milkvisits");
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        char e;
        cin >> e;
        if (e == 'H') {
            milkType.pb(true);
        } else {
            milkType.pb(false);
        }
        adj.pb({});
        visited.pb(false);
        componentOfCow.pb(0); // filler
    }
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            holstein.pb(milkType[i]);
            dfs(i);
            ++componentNum;
        }
    }
    // works
    for (int i = 0; i < M; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (componentOfCow[a] != componentOfCow[b]) {
            cout << "1";
        } else {
            int commonComponent = componentOfCow[a];
            bool commonMilkType = holstein[commonComponent];
            if (commonMilkType) {
                if (c == 'H') {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                if (c == 'G') {
                    cout << "1";
                } else {
                    cout << "0";
                }
            }
        }
    }
    return 0;
}

/*
IDea I didn't get is connected components, which makes so much sense, as you only need one cow of the milk you need, so only way there would be a no is if
someone travelled along the same connected component.

(Connected components: a bunch of cows which produce the same type of milk and are reachable from each other without having to go through a cow from another connected component.
e.g. sample case has 1, 2 and 4 as connected component since they all produce holstein milk

My program wokrs by looping through to find the connected components (DFS and move through edges only if the two cows have the same milk type)


If the two points in the path are in the same connected component (it must stay in that component since there is only 1 unique path which must've been the path the initial
search for connected components took, then it really depends on whether John's friends have the same preferred type of milk as the milk from the component.

If the two points are in different connected components, they must've gone from G to H or vice versa, so John's friends will be guaranteed to drink their type of milk.

*/


