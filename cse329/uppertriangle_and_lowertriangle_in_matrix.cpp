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
    cii(r,c);
    int mar[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mar[i][j];
        }
    }
    int lower[r][c];
    //for lower
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j > i){
                lower[i][j] = 0;
            }
            else{
                lower[i][j] = mar[i][j];
            }
        }   
    }

    int upper[r][c];
    //for upper
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j < i){
                upper[i][j] = 0;
            }
            else{
                upper[i][j] = mar[i][j];
            }
        }   
    }
    cout << "lower matrix" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << lower[i][j] << " ";
            if(j == c-1){
                cout << endl;
            }
        }   
    }
    cout << endl;
    cout << endl;
    cout << "upper matrix" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << upper[i][j] << " ";
            if(j == c-1){
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
 