// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//Euclidean Algo
//Time - O(min(a,b)) - by PMI - principle of mathematic induction

long long gcd(long long  a, long long  b) 
{ 
  if (b == 0)  return a; 
  return gcd(b, a % b); 
} 
  
  
// Function to return LCM of two numbers  
long long lcm(long long a, long long b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

int main() {
    long long n;
    cin>>n;
    long long ans=1;
    for(long long i=2;i<=n;i++){
        ans=lcm(ans,i);
    }
    cout<<ans<<endl;
}

//  Time complexity- O(N*N)
//  N is for outer loop and in inside let min(whole,N) =N then complexity is O(N*N) which is approcimately constant here

