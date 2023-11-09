class Solution {
public:
    int mod = 1000000007;
    int countHomogenous(string s) {
        long long ans = 0;
        long long count = 1;
        for(int i=1;i<s.length();i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else{
                ans += ((count*(count+1))/2)%mod;
                count = 1;
            }
        }
        
        ans += ((count*(count+1))/2)%mod;
        return ans;
    }
};