// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isValidURL(string s){
    string first="https://www.";
    string second="http://www.";
    
    bool a=false,b=false;
    int idx=-1,nextDot=-1;
    
    if(first==s.substr(0,12)) a=true;
    else if(second==s.substr(0,11)) b=true;
    else return false;
    
    
    if(a==true) idx=12;
    else idx=11;
    
    for(int i=idx;i<s.length();i++){
        if(s[i]=='.'){
            nextDot=i;
            break;
        }
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') || (s[i]=='-'))) return false;
    }

  
    
    if(nextDot==-1) return false;

      // checking whether domain size is between [2-256]
    if((nextDot-idx+1)<2 || (nextDot-idx+1)>256) return false;
    
    
    if(s.substr(nextDot+1) == "com/" || s.substr(nextDot+1) == "org/" || s.substr(nextDot+1) == "in/") return true;
    return false;
    
    
}

int main() {
    string str;
    cin>>str;
    if(isValidURL(str)) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
}

