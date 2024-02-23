#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity - O(2^(m+n))-- because we have 2 choices either taking the character from the st1 and str2
Space complexity- Recursive  stack space
*/

// MARK:- Function to print the interleaving strings
//DESCRIPTION :- it will print all the interleaving strings considering str1 from ith index and str2 from jth index
// with having a current string
void printInterleavings(int i, int j,string str1, string str2 , string current){

//MARK:- Base Case
//DESCRIPTION:- if we reached at the last of both str1 and str2 then it means that we got a interleaving string 
// so now we will print it and just simply return
if(i== str1.size() && j== str2.size()) {
    cout<<current<<" ";
    return ;
}


// MARK:- Doing operations if we are on str1
//DESCRIPTION:- if we are still at str1 then we will simply just add the current character to the current string 
// and then will make the recursive call for the rest to get the interleaving strings starting with current char
if(i != str1.size()){
    current+=str1[i];
    printInterleavings(i+1,j,str1,str2,current);
    current.pop_back();
}

// MARK:- Doing operations if we are on str2
//DESCRIPTION:- if we are still at str2 then we will simply just add the current character to the current string 
// and then will make the recursive call for the rest to get the interleaving strings starting with current char
if(j != str2.size()){
    current+=str2[j];
    printInterleavings(i,j+1,str1,str2,current);
    current.pop_back();

}

}

int main(){
    string str1,str2;
    cout<<"Enter String 1"<<endl;
    cin>>str1;
    cout<<"Enter String 2"<<endl;
    cin>>str2;

    cout<<"Output Strings are"<<endl;

    // Function calling to print the Interleaving strings
    printInterleavings(0,0,str1,str2,"");
}