//sudoku solver is made of 9 matrix of 3 * 3 
/*
 main points --
 1 -- every col have 1-9 elements one time only and all have to present
 2 -- every row have 1-9 elements one time only and all have to present
 3 -- in every matrix of 3 * 3 we must have 1-9 element 
 */
 
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int board[N][N], int i, int j, char k)
    {
        // Block no. is i/3, first element is i/3*3
        int blkrow = (i / 3) * 3, blkcol = (j / 3) * 3;
        
        for(int a=0; a<9; a++)
        {
            if(board[i][a] == k)    return false;
            if(board[a][j] == k)    return false;
            if(board[blkrow + a / 3][blkcol + a % 3] == k)    return false;
        }
        return true;
    }


    bool solve(int board[N][N], int row, int col)
    {
        for(int i=row; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == 0)
                {
                    for(char k=1; k<=9; k++)
                    {
                        if(check(board, i, j, k))
                        {
                            board[i][j] = k;   
                            if(solve(board, i, j))    return true;
                            else    board[i][j] = 0;
                        }
                    }
                    //If none of the numbers can be placed here, it's the 
                    //wrong approach. Hence, backtrack.
                    return false;
                }
            }
        }
        //Outside both for loops
        return true;  //no vacant spaces available; Hence sudoku is solved!
    }
    
    bool SolveSudoku(int board[N][N]) {
        return solve(board, 0, 0);
    } 
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int row=0; row<9; row++)
        {
            for(int col=0; col<9; col++)
            {
                cout<<grid[row][col]<<" ";
            }
        }
    }
};


int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		// for(int i=0;i<9;i++)
		//     for(int j=0;j<9;j++)
		//         cin>>grid[i][j];
		grid[][] = 
                    {{3 0 6 5 0 8 4 0 0},
                    {5 2 0 0 0 0 0 0 0},
                    {0 8 7 0 0 0 0 3 1},
                    {0 0 3 0 1 0 0 8 0},
                    {9 0 0 8 6 3 0 0 5},
                    {0 5 0 0 9 0 6 0 0},
                    {1 3 0 0 0 0 2 5 0},
                    {0 0 0 0 0 0 0 7 4},
                    {0 0 5 2 0 6 3 0 0}};       
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
 