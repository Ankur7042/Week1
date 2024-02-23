#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity - O(N*logk)  in worst case it will become Nlog(N) when we window size will be N
Space complexity - O(K) -- size of set
*/

int main(){
    int length,Window_Len;
    cout<<"Enter length of the array"<<endl;
    cin>>length;
    vector<int>v(length);
    cout<<"Enter Array Elements"<<endl;
    for(int i=0;i<length;i++){
        cin>>v[i];
    }
    cout<<"Enter Window Length"<<endl;
    cin>>Window_Len;

//Set to give the maixmum element
    set<pair<int,int>,greater<pair<int,int>>> st;

    //MARK:- inserting the current window element and its index as a pair
    for(int i=0;i<Window_Len;i++){
        st.insert({v[i],i});
    }
    
 // printing the maximum of the first window
    cout<<(st.begin())->first<<" ";

// MARK:- Traversing rest windows
//DESCRIPTION:- adding a new element everytime and removing the element out of window
    for(int i=Window_Len;i<length;i++){
        st.erase({v[i-Window_Len],i-Window_Len});
        st.insert({v[i],i});

        cout<<(st.begin())->first<<" ";
    }
    cout<<endl;
}