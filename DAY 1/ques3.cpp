// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// O(logn) - going on each digit 
bool isPrime(long long num,vector<bool>& prime){
    while(num>0){
        int dig=num%10;
        num/=10;
        if(prime[dig]==0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin>>n;
    vector<bool>prime(10,0);
    prime[2]=1;
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    
    // O(n*logn)
    bool d=false;
    for(long long i=n-1;i>1;i--){
        if(isPrime(i,prime)){
            d=true;
            cout<<i<<endl;
            break;
        }
    }
    if(!d) cout<<-1<<endl;
    
}

 

