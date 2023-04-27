#include <bits/stdc++.h>
 
#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
using namespace std;
 
//in this we have to find the number of meeting in room.

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

void krdiyasuru()
{
    ci(n);
    int start[n];
    int end[n];
    for(int i=0;i<n;i++){
        cin>> start[i];
    }
    for(int i=0;i<n;i++){
        cin >> end[i];
    }

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        pair<int,int> p = make_pair(start[i],end[i]);
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp);
    int count = 1;
    int lol = v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].first > lol){
            count++;
            lol = v[i].second;
        }
    }
    cout << count << endl;
}
 
int main()
{
    yehbhitheekhai;
    //    solve();
        krosuru
    {
        krdiyasuru();
    }
}
 