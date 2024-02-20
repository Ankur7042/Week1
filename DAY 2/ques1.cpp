#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){
    // map to store the count of elements
    unordered_map<int,int>mp;
    
    // vector to store the unique elements 
    vector<int>ans;
    for(auto i : arr) mp[i]++;

   // traversing the map and then pushing the unique elemets from the map
    for(auto i : mp){
       ans.push_back(i.first);
    }
    return ans;

}

int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int>arr;
    cout<<"Enter the numbers"<<endl;
    
    //Taking input from user
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
 
 // fuction call and then printing the answer
    vector<int>received=removeDuplicates(arr);
    for(auto i : received){
        cout<<i<<" ";
    }
}

//time complexity- O(N)
// space complexity - O(N)- for map