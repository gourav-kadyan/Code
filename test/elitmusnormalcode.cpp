#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, editors_count;
    cin >> n;

    vector<int> reels(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        reels.push_back(val);
    }

    cin >> editors_count;

    while (true) {
        sort(reels.begin(), reels.end());

        int min_time = 0;
        for (int i = n - 1; i >= n - editors_count; i--) {
            min_time += reels[i];
        
        }

        if (min_time == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            reels[i] -= min_time;
            if (reels[i] < 0) {
                reels[i] = 0;
            }
        }
    }

    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += reels[i];
    }

    cout << total_time << endl;

    return 0;
}
