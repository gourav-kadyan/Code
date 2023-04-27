vector<int> FactDigit(int N)
{
    // Code here
    vector<int>ans;
    vector<int>fact(10,0);
    fact[0]=1;
    for(int i=1;i<10;i++){
        fact[i]=i*fact[i-1];
    }
    for(int i=9;i>=1;i--){
        while(N>=fact[i]){
            ans.push_back(i);
            N-=fact[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}