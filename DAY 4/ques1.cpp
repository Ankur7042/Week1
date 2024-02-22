#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity - O(rows*cols) 
Traversing the matrix

Space complexity-O(1)- no space except Input Vector
*/

//MARK :- Printing the array Clockwise Direction
void printClockwise(vector<vector<int>> matrix,int rows,int cols){
     // MARK:- variables for traversing 
    // Description :- four  variables one for starting , other for end col , other for startRow , other for end row
    int startCol=0,endCol=cols-1,startRow=0,endRow=rows-1;

    // variable for count the number of elements on which we are traversing
    int countElements=0;
    while(countElements <= rows*cols){

      // MARK :- Traversing in the right direction
        for(int  i=startCol;i<=endCol;i++){
            cout<<matrix[startRow][i]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        startRow++;
            if(countElements == rows*cols) break;

      // MARK:- Traversing in the downward direction
        for(int  i=startRow;i<=endRow;i++){
            cout<<matrix[i][endCol]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        endCol--;
            if(countElements == rows*cols) break;

        // MARK:-Traversing in left direction 
        for(int  i=endCol;i>=0;i--){
            cout<<matrix[endRow][i]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        endRow--;
            if(countElements == rows*cols) break;

     // MARK:- Traversing in the Upward direction
        for(int  i=endRow;i>=startRow;i--){
            cout<<matrix[i][startCol]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
            if(countElements == rows*cols) break;
        startCol++;

    }
}

//MARK :- Printing the array anticlockwise
void printAntiClockwise(vector<vector<int>> matrix,int rows,int cols){
    // MARK:- variables for traversing 
    // Description :- four  variables one for starting , other for end col , other for startRow , other for end row
    int startCol=cols-1,endCol=0,startRow=0,endRow=rows-1;
    
    // variable for count the number of elements on which we are traversing
    int countElements=0;
    while(countElements <= rows*cols){

        // MARK:-Traversing in left direction 
        for(int  i=startCol;i>=endCol;i--){
            cout<<matrix[startRow][i]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        startRow++;
            if(countElements == rows*cols) break;

      // MARK:- Traversing in the downward direction
        for(int  i=startRow;i<=endRow;i++){
            cout<<matrix[i][endCol]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        endCol++;
            if(countElements == rows*cols) break;
              
      // MARK :- Traversing in the right direction
        for(int  i=endCol;i<=startCol;i++){
            cout<<matrix[endRow][i]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
        endRow--;
            if(countElements == rows*cols) break;

     // MARK:- Traversing in the Upward direction
        for(int  i=endRow;i>=startRow;i--){
            cout<<matrix[i][startCol]<<" ";
            countElements++;
            if(countElements == rows*cols) break;
        }
            if(countElements == rows*cols) break;
        startCol--;

    }
}

int main(){
  int rows,cols;
    cout<<"Enter number of rows"<<endl;
    cin>>rows;
    cout<<"Enter number of coloumns"<<endl;
    cin>>cols;
    vector<vector<int>> matrix(rows,vector<int>(cols));
    cout<<"Enter Grid values"<<endl;
 // MARK:- Taking input from the USER
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }


cout<<"Matrix after Clockwise priting ="<<endl;
    printClockwise(matrix,rows,cols);
    cout<<endl;
cout<<"Matrix after antiClockwise printing ="<<endl;
    printAntiClockwise(matrix,rows,cols);


}