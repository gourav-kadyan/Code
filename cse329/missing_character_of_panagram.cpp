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

    string p;
    getline(cin,p);
    string s = "";
    for(int i=0;i<p.length();i++){
        if(p[i] == ' '){
            continue;
        }
        else{
            s += p[i];
        }
    }
    sort(s.begin(), s.end());
    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string ans = "";
    int j=0;
    int i=0;
    while(i < s.length())
    {
        if(s[i] == arr[j]){
            j++;
            i++;
        }
        else if(s[i] > arr[j]){
            ans += arr[j];
            j++;
        }
        else{
            i++;
            continue;
        }
    }
    if(j < 26){
        for(int i=j;i<26;i++){
            ans += arr[i];
        }
    }
    cout << ans << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
    //    krosuru
    {
        krdiyasuru();
    }
}
 