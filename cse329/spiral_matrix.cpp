#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int low = 0;
        int bottom = r-1;
        int right = c-1;
        int left = 0;
        while(low <= bottom && left <= right){
            for(int i=low;i<=right;i++){
                ans.push_back(matrix[low][i]);
            }
            low++;
            if(low <= bottom && left <= right){
                for(int i=low;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(low <= bottom && left <= right){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(low <= bottom && left <= right){
                for(int i=bottom;i>=low;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}