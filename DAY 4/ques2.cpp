#include<bits/stdc++.h>
using namespace std;
// MARK:- function to generate the combinations
// DESCRIPTION:- this function generates all the possible combinations with initially current string 
// and generate the combinations from the index
void GenerateCombinations(string &inputValue,int index,unordered_map<string,vector<char>> &mp,string current){
    if(index == inputValue.size()){
        cout<<current<<" ";
        return;
    }

// Travelling on the all the characters of the index and then adding it to the current
    string digit="";
    digit += inputValue[index];
        for(auto x : mp[digit]){
            GenerateCombinations(inputValue,index+1,mp,current+x);
        }
}

int main(){
    unordered_map<string,vector<char>> mp={
        {"1",{'Z','Y','A'}},
        {"2",{'B','O'}},
        {"12",{'L'}},
        {"3",{'U','P'}}
    };


    string inputValue="121";

    string key = "";
    for(int i=0; i<inputValue.size(); i++){

//MARK:-passing the key 
// DESCRIPTION:- in starting i will pass the '1' then '12' then '121' 
        key+= inputValue[i];
        for(auto val : mp[key]){

            // converting the character into the string so that i can pass
            string pass = "";
            pass += val;
       GenerateCombinations(inputValue,i+1, mp ,pass);
        }

    }
    

}