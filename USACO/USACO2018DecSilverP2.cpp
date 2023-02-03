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
    setIO("convention2");
    int time = 0;
    int lineIndex = 0;
    int currentCowEnd = 0; // when the first cow in line stops eating
    int N;
    cin >> N;
    int ans[N+1]; // indexed according to seniority
    memset(ans, 0, sizeof(ans));
    priority_queue<pair<int, pair<int, int>>> lineUp; // seniority, time
    vector<pair<pair<int, int>, int>> cows = {};
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        cows.pb({{a, b}, -1*i});
    }
    sort(cows.begin(), cows.end());
    // works
    while (lineIndex < N || !lineUp.empty()) { // line index
        //cout << "TIME AND INDEX: " << lineIndex << " " << time << "\n";
        auto cow = cows[lineIndex];
        //cout << "CURRENT COW TO BE ADDED: " << cow.first.first << " " << cow.first.second << " " << cow.second << "\n";
        if (lineUp.empty()) {
            lineUp.push(make_pair(cow.second, make_pair(cow.first.first, cow.first.second)));
            time = ((cow.first.first + cow.first.second));
            ++lineIndex; // note: cow at lineIndex isn't automatically added.
        } else {
            auto oldCow = lineUp.top();
            //cout << "COW REMOVED: " << oldCow.first << " " << oldCow.second.first << " " << oldCow.second.second << "\n";
            lineUp.pop();
            int index = -1*oldCow.first;
            //cout << "TIME FOR COW WITH SENIORITY: " << index << "\n";
            //cout << time << " - " << oldCow.second.first << " - " << oldCow.second.second << "\n";
            ans[index] = (time - oldCow.second.first - oldCow.second.second); // cow before lineIndex is the one in the stack
            // add new cows to replace the old ones
            int currentTime = cows[lineIndex].first.first;
            while ((time > currentTime) && (lineIndex < N)) {

                lineUp.push(make_pair(cows[lineIndex].second, make_pair(cows[lineIndex].first.first, cows[lineIndex].first.second)));
                //cout << "COW ADDED: " << cows[lineIndex].second << " " << cows[lineIndex].first.first << " " << cows[lineIndex].first.second << "\n";
                ++lineIndex;
                if (lineIndex != N) {
                    currentTime = cows[lineIndex].first.first;
                }
            }
            auto topCow = lineUp.top();
            time += topCow.second.second;
        }
    }
    int maxWait = 0;
    for (int i = 1; i <= N; ++i) {
        //cout << ans[i] << " ";
        if (ans[i] > maxWait) {
            maxWait = ans[i];
        }
    }
    //cout << "\n";
    cout << maxWait;
    return 0;
}

/*

The biggest headache was looping through that array and adding the new cows since the program would reach the end of the loop and not know what to do.

My pseudocode was.

sort everything in order of arrival time.

generate a priority queue that prioritizes seniority (since all cows waiting automatically defer to the one with seniority)

have a time variable

have an answer array that stores the wait for each cow, with the index representing seniority.

if priority queue is empty:
        add the newest cow to arrive in that list
        change the time to right after the cow is done eating the grass
else:
        get rid of the cow that's currently eating, record the time the cow took to wait (which is roughly current time - time the cow arrived - time it took for cow to eat), the cow's just done eating, current time - time it took for cow to eat = time cow actually started
        loop through the array to add all the cows that joined while the current cow was eating <- somehow the hardest part since the program didn't know when the loop added
        change the time to right after the cow is done eating the grass.

I'm trying to write more pseudocode since I code so slow.

I had many bugs.

*/
