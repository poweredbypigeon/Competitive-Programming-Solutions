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

bool cmp (const int x, const int y) {
    return x > y;
}

bool cmp2 (const pii x, const pii y) {
    if (x.first == y.first) {
        return x.second > y.second; // won't happen but whatevs
    }
    return x.first > y.first;
}
// descending order

int main() {
    setIO("rental");
    vector<int> cows;
    vector<long long> cowMoney; // how much money farmer john can make off cow x.
    vector<pii> milk;
    vector<int> rent;
    int N, M, R;
    cin >> N >> M >> R;
    long long totalCowMoney = 0;
    int cowIndex = 0;
    int milkOrderIndex = 0;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        cows.pb(c);
        cowMoney.pb(0);
    }
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < M; ++i) {
        int q, p;
        cin >> q >> p;
        milk.pb({p, q});
    }
    sort(milk.begin(), milk.end(), cmp2);
    for (int i = 0; i < R; ++i) {
        int r;
        cin >> r;
        rent.pb(r);
    }
    sort(rent.begin(), rent.end());
    // cow milk assignment
    int milkLeft = cows[cowIndex];
    while (milkOrderIndex < M && cowIndex < N) {
        pii refPair = milk[milkOrderIndex];
        int milkToDraw = min(milkLeft, refPair.second);
        milkLeft -= milkToDraw;
        milk[milkOrderIndex].second -= milkToDraw; // iterator wouldn't let me edit.
        cowMoney[cowIndex] += (long long) (milkToDraw * refPair.first);
        // cout << cowIndex << " " << cowMoney[cowIndex] << "\n";
        if (milkLeft == 0) {
            ++cowIndex;
            milkLeft = cows[cowIndex];
        }
        if (milk[milkOrderIndex].second == 0) {
            ++milkOrderIndex;
        }
    }
    /*for (auto r : cowMoney) {
        cout << r << " ";
    }
    cout << "\n";*/
    // handle the rent
    for (int i = 0; i < min(N,R); ++i) {
        if (cowMoney[(N-1)-i] < rent[(R-1)-i]) {
            cowMoney[(N-1)-i] = rent[(R-1)-i];
        }
    }
    for (auto r : cowMoney) {
        totalCowMoney += r;
    }
    cout << totalCowMoney << "\n";
    return 0;
}

/*
We can use a greedy algorithm: 
- rent out the low production cows to the highest bidders
- make the high production cows produce milk
- fulfill the orders with the highest p_i first. 

This program is a 2 step program. It assumes we're only milking the cows. 

First we sort the cows with the low production cows appearing later. Next, we sort the milk offers with the bad milk offers (lower pi) appearing later. Finally, we sort the rent offers with the highest bids appearing later.

So what this does is that it assigns the highest milk producing cows the best milk offers as we're highly unlikely to change the ordering around if we decide we want to rent out the lesser cows

If we do rent out the cows, then we still ensure the highest offers go to the cows that are still milking.

7 6 4 2 1
- 25 cents x 7, 1.75
- 25 cents x 3, 15 cents x 3, 1.20
- 15 cents x 4, 0.60
- 15 cents x 2, 0.30
- 15 cents, 0.15

Then we start renting out the cows, starting with the highest bid for rent and the cow that generates the least money based on milk
As we move up the array

Since the money is increasing and the rent money is decreasing, we:

- rent out the 1 cow for $2.50 ($2.50 > $0.15)
- rent out the 2 cow for $1.00 ($1.00 > $0.30)
- rent out the 3 cow for $0.80 ($0.80 > $0.60)
- prepare to rent out the 4 cow for $0.40, but then realizing that you're losing 80 cents this way and not going through with it. ($0.40 < $1.20) 

Another sample case that might be useful might be

5 3 4
6
2
4
7
1
5 25
3 50
15 15
250
80
100
40
*/
