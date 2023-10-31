class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // xor property a ^b = c  then a ^ c = b
        if(pref.size() == 1){
            return pref;
        }
        vector<int> ans;
        int value = pref[0];
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
           value = pref[i-1] ^ pref[i];
           ans.push_back(value);
        }
        return ans;
    }
};