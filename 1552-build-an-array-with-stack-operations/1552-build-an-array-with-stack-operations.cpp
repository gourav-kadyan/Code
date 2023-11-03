class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string s = "Push";
        string st = "Pop";
        int x = 1;
        int i=0;
        while(x <= n){
            if(i == target.size()){
                break;
            }
            if(target[i] != x){
                ans.push_back(s);
                ans.push_back(st);
            }
            else{
                i++;
                ans.push_back(s);
            }
            x++;
        }
        return ans;
    }
};