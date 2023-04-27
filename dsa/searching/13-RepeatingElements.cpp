#include <bits/stdc++.h>
 

#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 

using namespace std;
//repeating elements
// conditions --
// only one element is repeating 
// arrys values upto 0 to arr[max]

//bool sol 
// time - O(n) Space - O(n)
int repeat(vector<int> &v, int n){
    bool visit[n];
    memset(visit, false , sizeof(visit));
    for(int i=0;i<n;i++){
        cout << visit[i] << endl;

        if(visit[v[i]]==true)
            return v[i];
        visit[v[i]] = true; 
    }
    return -1;
}


void krdiyasuru()
{
    ci(n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        //v.push_back(temp);
        v[i] = temp;
    }
    int res = repeat(v,n);
    cout << endl;
    cout << res << endl;
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
 