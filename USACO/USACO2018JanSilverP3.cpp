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

int videos = -1;

vector<vector<pii>> adj = {{}}; // 1 indexed
vector<bool> visited = {true};
vector<bool> references = {true};

void dfs (int s, int minRel) {
    if (visited[s]) {
        return;
    }
    // cout << "DFS: " << s << " " << minRel << "\n";
    ++videos;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (u.second >= minRel) {
            dfs(u.first, minRel);
        }
    }
}


int main()
{
    setIO("mootube");
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        adj.pb({});
        visited.pb(false);
        references.pb(false);
    }
    for (int i = 1; i < N; ++i) {
        int p, q, r;
        cin >> p >> q >> r;
        adj[p].pb({q, r});
        adj[q].pb({p, r});
    }
    for (int i = 0; i < Q; ++i) {
        int k, v;
        cin >> k >> v;
        dfs(v, k);
        cout << videos << "\n";
        videos = -1; // decrement by one because video v doesn't count
        visited = references;
    }
    return 0;
}

/*
Manually run queries by traversing through the graph throughout, since N and Q are small enough.

You can go from one video to another if the minimum relevance during the path you take is greater than or equal to K, which is pretty much the same thing as:
"if the relevance is less than K, you can't go from this video to the other one."

*/


