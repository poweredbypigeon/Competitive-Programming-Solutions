#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef vector<int> vi; 
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd; 
typedef vector<ULL> vull; 
typedef unsigned int UI;
typedef long long int LLI;
typedef pair<int, int> pii;
typedef pair<ULL, ULL> pull;
typedef double db; 
typedef pair<db, db> pdb; 
typedef long double ld; 

#define pf push_front
#define pb push_back 
#define sz(x) (int) x.size()
#define vrange(x) x.begin(), x.end()

#define INF 0x3f3f3f3f

const int MOD = 1e9 + 7; 
const int OTHER_MOD = 998244353; 
const int BIG_INTEGER = 999999999; 

/* void pop_front(vector<int>& v) {
    if (v.size > 0) {
        v.erase(v.begin());
    }
} */

void printArray(int* arr, size_t size) { // only for arrays, 1st arg is a pointer. 
    for (int i = 0; i < size; ++i) {
        cout << *arr++ << endl;
    }
}
// add scanf and printf alternatives. 
// add GCD/LCM.
// add memset. 
// add a merge sort or quick sort. 
// add a binary search. 

/*
Alternatively: copy and paste
for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
}
*/


// This file passes the additional test data from dmoj.ca

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vvi adjM; 
    vector<bool> visited;
    string outcome = "unknown";
    deque<int> queue; 
    for (int i = 0; i < N; ++i) {
        adjM.pb({});
        visited.pb(false);
    } // no effect on complexity.
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B; 
        adjM[B - 1].pb(A); 
    }
    int A, B;
    cin >> A >> B;
    queue.pb(B);
    while (queue.size() != 0) {
        int first = queue[0];
        queue.pop_front(); 
        for (auto a : adjM[first - 1]) {
            if (!visited[a]) {
                queue.pb(a);
                visited[a] = true; 
            }
            if (a == A) {
                outcome = "yes"; 
                break;  
            }
        }
    }
    visited = {};
    queue = {A};
    while (queue.size() != 0) {
        int first = queue[0];
        queue.pop_front();
        for (auto a : adjM[first - 1]) {
            if (!visited[a]) {
                queue.pb(a);
                visited[a] = true;
            }
            if (a == B) {
                outcome = "no";
                break;
            }
        }
    }
    cout << outcome; 
}
