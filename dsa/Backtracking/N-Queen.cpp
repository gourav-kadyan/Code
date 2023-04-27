/* 
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isSafe(int row,int col,vector<vector<int> >& board,int n){
        int x = row;
        int y = col;
        //chek for row 
        while(x >=0 && y >=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        //chk for upper diagonal    
        x = row;
        y = col;
        while(x >=0 && y >=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //chk for lower diagonal
        x = row;
        y = col;
        while(x < n && y >=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void add(vector<vector<int> > &board, vector<vector<int>> &ans,int n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }
    void solve(int col,vector<vector<int> >& board,vector<vector<int>> &ans,int n){
        if(col == n){
            add(board,ans,n);
            return;
        }
        //1 case rest done by recursion
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 1;
                solve(col+1,board,ans,n);
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        solve(0,board,ans,n);
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}