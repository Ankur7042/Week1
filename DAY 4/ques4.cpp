#include<bits/stdc++.h>
using namespace std;

/*
Time complexity - O(m*n) ;
Space complexity -O(m*n) - for visited and 
*/

// dfs call for marking the neighbours as visited
void dfs(vector<vector<int>> grid, vector<vector<bool>>& visited,int i, int j){

    // MARK:- if the current index is out of bound then simply return
    if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1) return;

// MARK:- mark the current index as visited
    visited[i][j]=1;


    if(grid[i][j]==1){
        // MARK:- marking the current one as 0
        //DESCRIPTION :- we are marking the grid[i][j]=0 so that if we go on neighbour of (i,j) then it will not 
        // be able to make the recursive call on grid[i][j] again.
        grid[i][j]=0;
    
    // for upward direction
    dfs(grid,visited,i-1,j);

    // for downward direction
    dfs(grid,visited,i+1,j);
    
    // for left direction
    dfs(grid,visited,i,j-1);

    // for right direction
    dfs(grid,visited,i,j+1);
    }
}

int main(){
  int rows,cols;
    cout<<"Enter number of rows"<<endl;
    cin>>rows;
    cout<<"Enter number of coloumns"<<endl;
    cin>>cols;
    vector<vector<int>> grid(rows,vector<int>(cols));
    cout<<"Enter Grid values"<<endl;
 // MARK:- Taking input from the USER
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>grid[i][j];
        }
    }

 // MARK:-  variable to store the answer
    int islands=0;

    // MARK:- visited array
    //Description :- it stores whether the (i,j) is visited or not already
    vector<vector<bool>> visited(rows,vector<bool>(cols,0));

// MARK:- Making the recursive calls and increasing the count of islands
//Description :- if the particular block is not visited and also it is 1 then we will increase the island count
// because we know that it is a connected component and thus on recursive call it will mark all the neighbours 
// as true that are potential one's
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && grid[i][j] == 1){
                islands++;
                dfs(grid,visited,i,j);
            }
        }
    }


    cout<<"NUmber of Islands are = "<<islands<<endl;


}