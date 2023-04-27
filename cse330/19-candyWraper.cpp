#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int
#define mod 1000000007
#define pq priority_queue
#define pb push_back
#define ld long double
#define REP(x, n) for (int x = 0; x < n; x++)

using namespace std;

class Solution {
   public:
};

void candy(int w, int price, int &ans) {
    int c = w / price;
    if (c == 0)
        return;
    w = w % price;
    ans += c;
    w += c;
    candy(w, price, ans);
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("Input1.txt", "r", stdin);
//     freopen("Output1.txt", "w", stdout);
// #endif

    // int T;
    // cin >> T;
    // while (T--) {
        Solution ob;
        int money, price, wrap;
        cin >> money >> price >> wrap;
        int ans = 0;
        ans = money / price;
        int w = ans;
        // cout << w << endl;
        candy(w, wrap, ans);
        cout << ans << endl;
    //}
    return 0;
}