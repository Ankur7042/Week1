#include<bits/stdc++.h>
using namespace std;

/* Time complexity of code-O(log(row) + log(col))--> 
  log(row) --> for binary Search on row
  log(col) ---> for binary search on col

  Space Compelxity of the code - O(1)- constant except the input matrix
*/

//MARK:- function for searching element in row
//Description:- This function checks whether given target is present in the Row or not that i have passed as an argument
bool isPresentInRow(vector<vector<int>> v, int target ,int Row , int cols){
    
    //MARK:- Variables for Binary search
    int low=0,high=cols-1;
    while(low<high){
        int mid=low+(high-low)/2;

  // MARK:- if we  got the target then we will return true else we will search in new search space
        if(v[Row][mid] == target) return true;
        else if(v[Row][mid] < target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

int main(){
    int rows,cols;
    cout<<"Enter number of rows"<<endl;
    cin>>rows;
    cout<<"Enter number of coloumns"<<endl;
    cin>>cols;
    int target;
    cout<<"Enter Target"<<endl;
    cin>>target;

    vector<vector<int>> v(rows,vector<int>(cols));
    cout<<"Enter matrix values"<<endl;
 // MARK:- Taking input from the USER
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>v[i][j];
        }
    }

//MARK:- Variables for Binary search
    int low=0,high=rows-1;

    //MARK:- this variable tell whether element is present in the whole 2-d array or not
bool isElementPresent=false;

//MARK:- binary searching the row in which element can be present
    while(low<=high){
        int midRow=low+(high-low)/2;

// MARK:-Checking if the element is lies in the range of this row 
//DEScription:-  if element lies in the range of this row then we will gonna call the isPresentInRow function
// if it gives true it means that element is present in the row otherwise not.
        if(target>=v[midRow][0] && target<=v[midRow][cols-1]){
            if(isPresentInRow(v,target,midRow,cols)) {
                isElementPresent=true;
                break;
            }
        }
        // IF element is less than the 0th index value of row then we will decrease the search space
         if(target<v[midRow][0]) high=midRow-1;
        else  low=midRow+1;
}

if(!isElementPresent) cout<<"Element is not Present"<<endl;
else cout<<"Element is Present"<<endl;

}