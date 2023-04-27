#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
int rem(string s1, string s2)
{
    int arr[26] = {0};
    int count =0;
    for(int i=0;i<s1.length();i++){
        int lol = s1[i] - 'a';
        arr[lol]++;
    }
    for(int i=0;i<s2.length();i++){
        int lol = s2[i] - 'a';
        arr[lol]--;
    }
    for(int i=0;i<26;i++){
        if(arr[i] != 0){
            count += abs(arr[i]);
        }
    }
    return count;
}
void krdiyasuru()
{
    string s1,s2;
    cin>>s1>>s2;
    int ans = rem(s1,s2);
    cout << ans << endl;
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
 