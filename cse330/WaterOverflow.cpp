#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    double waterOverflow(int K, int R, int C) {
        double ans[101][101] = {0.0};
        ans[0][0] = K;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                double left = (ans[i][j]-1)/2.0;
                if(ans[i][j] >= 1){
                    ans[i+1][j] += left*1.0;
                    ans[i+1][j+1] += left*1.0;
                    ans[i][j] = 1;
                }
            }
        }
        return ans[R-1][C-1]*1.000000;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        //cout <<setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
        printf("%.6f",ob.waterOverflow(K,R,C));
    }
    return 0;
}