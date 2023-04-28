#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    cin >> k;
    vector<int> ans;

    map<int,int> mp;
    for(auto it: v){
        mp[it]++;
    }

    vector<pair<int,int> > var(mp.begin(),mp.end());


    
}