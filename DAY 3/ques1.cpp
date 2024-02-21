#include<bits/stdc++.h>
using namespace std;


// time-O(9)
// space - O(9)-- this is temporary memory so after it will exit from function this memory will be deleted 
bool isvalidRow(vector<vector<char>> &v , int row , int col){
    set<char>st;
    // traversing on the current row
    for(int i=0;i<9;i++){
        if(v[row][i]=='.') continue;
        // means value is already present so we return false;
        if(st.find(v[row][i]) != st.end()) return false;
        if(v[row][i]!='.') st.insert(v[row][i]);
    }
    return true;
}


// time-O(9)
// space - O(9)-- this is temporary memory so after it will exit from function this memory will be deleted 
bool isvalidCol(vector<vector<char>> &v , int row , int col){
    set<char>st;
    // traversing on the current col
    for(int i=0;i<9;i++){
        if(v[i][col]=='.') continue;

        // means value is already present so we return false;
        if(st.find(v[i][col]) != st.end()) return false;
        if(v[i][col]!='.') st.insert(v[i][col]);
    }
    return true;
}

// time-O(9)
// space - O(9)-- this is temporary memory so after it will exit from function this memory will be deleted 
bool isvalidBox(vector<vector<char>> &v , int startRow , int startCol){

    set<char>st;
    // traversing on the box with initial element as v[startRow][startCol]
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[startRow+i][startCol+j] == '.') continue;

// if curr element is present in the set already then return false
            if(st.find(v[startRow+i][startCol+j]) != st.end()) return false;
         if(v[startRow+i][startCol+j]!='.') st.insert(v[startRow+i][startCol+j]);   
        }
    }
    return true;
}

int main(){
    // vector<vector<char>>v(9,vector<char>(9));
    // for(int i=0;i<9;i++){
    //     for(int j=0;j<9;j++){
    //         cin>>v[i];
    //     }
    // }

vector<vector<char>> v= {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', 'x', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

//    bool isInputFormatValid=true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!((v[i][j]>='1' && v[i][j]<='9') || v[i][j]=='.')){
                cout<<"Input Value Invalid"<<endl;
                return 0;
            }
        }
    }



// boolean check is true it means that we are assuming that row , col and boxe are valid currently
        bool check=true;
// traversing on the 9*9 matrix
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            //  checking if the current row , col and the box that contains this element is valid or not
            if(!(isvalidRow(v,row,col) && isvalidCol(v,row,col) && isvalidBox(v,row-row%3,col-col%3))){
                check=false;
                break;
            }
            if(!check) break;
        }
    }
 
    if(check) cout<<"true"<<endl;
    else cout<<"false"<<endl;

}

//Time complexity for code - O(N*N*N) ----> O(9*9*9)
//space complexity -- O(1)
