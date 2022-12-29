#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll low = 1;
    ll high = 2000000000;
    ll med = 0;
    while (true) {
        med = (low + high) / 2;
        cout << med << endl;
        string feedback;
        cin >> feedback;
        if (feedback == "SINKS") {
            low = med;
            ++low;
        } else if (feedback == "FLOATS") {
            high = med;
            --high;
        } else {
            break;
        }
    }
    return 0;
}


