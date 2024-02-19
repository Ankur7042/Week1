#include <bits/stdc++.h>
using namespace std;

 bool isNameValid(string  name){
     unordered_map<char,vector<int>>mp;
     for(int i=0;i<name.length();i++){
         mp[name[i]].push_back(i);
     }
     
if(mp['a'].size()>1 || mp['e'].size()>1 || mp['i'].size()>1 || mp['o'].size()>1 || mp['u'].size()>1 || mp['A'].size()>1
||mp['E'].size()>1 ||mp['I'].size()>1 ||mp['O'].size()>1 ||mp['U'].size()>1   ) {
    return false;
}

  vector<int>v=mp['S'];
//   int x=v.size();

for(int i=0;i<v.size()-1;i++){
    int curr=v[i];
    int next=v[i+1];
    for(int j=curr+1;j<next;j++){
        if(name[j]=='T') return false;
    }
}

return true;

 }

int main() {
    string str;
    // cout<<"YS"<<endl;
    cin>>str;
     bool ans=isNameValid(str);
     cout<<ans;
}

// Time complexity- O(N)
// Space complexity-O(N)