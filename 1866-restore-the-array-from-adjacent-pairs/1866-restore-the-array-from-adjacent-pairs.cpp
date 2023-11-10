class Solution {
public:

    vector<int> bfs(unordered_map<int,unordered_set<int>> &mp, int single){
        vector<int> v;
        queue<int> q;
        q.push(single);
        unordered_map<int,int> visited;
        while(!q.empty()){
            int node = q.front();
            v.push_back(node);
            visited[node] = 1;
            q.pop();
            for(auto it:mp[node]){
                if(visited[it]){
                    continue;
                }
                else{
                    q.push(it);
                }
            }
        }
        return v;
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,unordered_set<int>> mp;
        unordered_map<int,int> gg;
        for(auto it:adjacentPairs){
            mp[it[1]].insert(it[0]);
            mp[it[0]].insert(it[1]);
            gg[it[0]]++;
            gg[it[1]]++;
        }
        int single = -1;
        for(auto it:gg){
            if(it.second == 1 && mp[it.first].size() > 0){
                single = it.first;
                break;
            }
        }
        vector<int> ans = bfs(mp,single);
        return ans;
    }
};