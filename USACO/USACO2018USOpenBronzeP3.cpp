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
    setIO("family");
    int currentNum = 1;
    map<string, int> cowowNames; // asign each cow a CowID
    int N;
    cin >> N;
    vector<int> adj[N+2]; // up to N + 1 cows
    string A, B;
    cin >> A >> B;
    for (int i = 0; i < N; ++i) {
        string C, D;
        cin >> C >> D;
        if (cowowNames[C] == 0) {
            cowowNames[C] = currentNum;
            ++currentNum;
        }
        if (cowowNames[D] == 0) {
            cowowNames[D] = currentNum;
            ++currentNum;
        }
        adj[cowowNames[D]].pb(cowowNames[C]); // in adj, adj[x] = y if y is x's mother
    }
    vector<int> pathA; // path from A up until oldest ancestor
    vector<int> pathB; // path from B up until oldest ancestor
    int X = cowowNames[A];
    while (true) {
        pathA.pb(X);
        if (adj[X].size() == 0) {
            break;
        }
        X = adj[X][0];
    }
    X = cowowNames[B];
    while (true) {
        pathB.pb(X);
        if (adj[X].size() == 0) {
            break;
        }
        X = adj[X][0];
    }
    // not sure if the search for a common ancestor is complete, just trying to find the 1st one.
    int LCAIndexA = -1;
    int LCAIndexB = -1; // how many family members up
    for (int i = 0; i < pathA.size(); ++i) {
        for (int j = 0; j < pathB.size(); ++j) {
            if (pathA[i] == pathB[j] && (LCAIndexA == -1)) {
                LCAIndexA = i;
                LCAIndexB = j;
                break; // DEBUG: stop if there are too many ancestors.
            }
        }
    }
    //cout << LCAIndexA << " " << LCAIndexB << "\n";    // casework
    if (LCAIndexA == -1 && LCAIndexB == -1) {
        cout << "NOT RELATED";
        return 0;
    }
    if (LCAIndexA == 0) {
        if (LCAIndexB == 1) {
            cout << A << " is the mother of " << B;
            return 0;
        } else {
            cout << A << " is the ";
            for (int i = 0; i < (LCAIndexB - 2); ++i) {
                cout << "great-";
            }
            cout << "grand-mother of " << B;
            return 0;
        }
    } else if (LCAIndexA == 1) {
        if (LCAIndexB == 0) {
            cout << B << " is the mother of " << A;
            return 0;
        } else if (LCAIndexB == 1) {
            cout << "SIBLINGS";
            return 0;
        } else {
            cout << A << " is the ";
            for (int i = 0; i < (LCAIndexB - 2); ++i) {
                cout << "great-";
            }
            cout << "aunt of " << B;
            return 0;
        }
    } else if (LCAIndexB == 0) {
        cout << B << " is the ";
        for (int i = 0; i < (LCAIndexA - 2); ++i) {
            cout << "great-";
        }
        cout << "grand-mother of " << A;
        return 0;
    } else if (LCAIndexB == 1) {
        cout << B << " is the ";
        for (int i = 0; i < (LCAIndexA - 2); ++i) {
            cout << "great-";
        }
        cout << "aunt of " << A;
        return 0;
    } else {
        cout << "COUSINS";
        return 0;
    }
}


// bruh this technically counts as an lca problem
/*
The key reason for choosing LCA is because a cow can't have more than one mother 
*/
