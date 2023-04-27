#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
 
void krdiyasuru()
{
    ciiii(r1,c1,r2,c2);
    while(c1 != r2){
        cout << "value of c1 and r2 is not matching" << endl;
        ciiii(r1,c1,r2,c2);
    }
    int m1[r1][c1];
    int m2[r2][c2];
    int ans[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> m1[i][j];
        }
    }
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> m2[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout << ans[i][j] << " ";
            if(j == c2-1){
                cout << endl;
            }
        }
    }
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
     //   krosuru
    {
        krdiyasuru();
    }
}
 