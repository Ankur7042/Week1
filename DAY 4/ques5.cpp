#include<bits/stdc++.h>
using namespace std;

// Time complexity-O(N*N) -- because we are traversing the 2-d matrix of N*N
//space complexity- O(1) -- no extra space except the input matrix

int main(){
    int size;
    cout<<"Size of 2-d matrix";
    cin>>size;
    vector<vector<int>> matrix(size,vector<int>(size));

    // MARK :- taking input
    // Description :- Taking input from the User.
    cout<<"Enter matrix Values"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>matrix[i][j];
        }
    }

    //MARK :- Tranposing the matrix
    //Description :- Tranposing the matrix means swapping (i,j) index value with (j,i) value
    for(int row=0;row<size;row++){
        for(int col=row+1;col<size;col++){
            int temp=matrix[row][col];
            matrix[row][col]=matrix[col][row];
            matrix[col][row]=temp;
        }
    }


 // MARK :- Reversing each row of the matrix
    for(int row=0;row<size;row++){
        reverse(matrix[row].begin(),matrix[row].end());
    }

    cout<<"Matrix after 90 degree clockwise rotation will be"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}