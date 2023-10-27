//expand from center
class Solution {
public:

    string solve(string s,int low, int high){
        while(low >= 0 && high < s.length() && s[low] == s[high]){
            low--;
            high++;
        }
        return s.substr(low + 1,high - low - 1);
    }
    string longestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        string ans = "";
        for(int i=0;i<s.length()-1;i++){
            string odd = solve(s,i,i);
            string even = solve(s,i,i+1);
            if(odd.length() > ans.length()){
                ans = odd;
            }
            if(even.length() > ans.length()){
                ans = even;
            }
        }
        return ans;
    }
};