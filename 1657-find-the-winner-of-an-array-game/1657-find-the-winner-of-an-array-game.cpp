class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int winner = max(arr[0],arr[1]);
        if(k == 1){
            return winner;
        }
        mp[winner]++;
        for(int i=2;i<arr.size();i++){
            winner = max(winner,arr[i]);
            mp[winner]++;
            if(mp[winner] >= k){
                return winner;
            }
        }
        
        return winner;
    }
};