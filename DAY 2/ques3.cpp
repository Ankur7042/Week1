#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter pattern rows"<<endl;
    cin>>n;

     // decides how many stars will be in the middle of the first row of lower half
    int lower_start;

  // printing the upper half i.e first n/2 rows
    for(int row=0;row<n/2;row++){
        for(int stars=0;stars<row;stars++){
            cout<<'*';
        }
        cout<<'\\';

        // number of stars that will print now is x
        int x=n-(2*(row+1));
        for(int stars=1;stars<=x;stars++){
            cout<<'*';
        }
        if(row==n/2-1) lower_start=x;
        
        cout<<'/';
     for(int stars=0;stars<row;stars++){
            cout<<'*';
        }
        cout<<endl;
    }

   // if number of rows are odd then printing that extra row
    if(n%2==1) {
     for(int stars=1;stars<=n/2;stars++){
            cout<<'*';
        }
        cout<<'/';
    for(int stars=1;stars<=n/2;stars++){
            cout<<'*';
        }
         cout<<endl;
    }

   
   // now printing the lower half rows i.e n/2
    for(int row=(n/2)-1;row>=0;row--){
        for(int stars=1;stars<=row;stars++){
            cout<<'*';
        }
        cout<<'/';


        for(int stars=1;stars<=lower_start;stars++){
            cout<<'*';
        }
        lower_start+=2;
        
        cout<<'\\';
        for(int stars=1;stars<=row;stars++){
            cout<<'*';
        }
        cout<<endl;
    }

}

//Time complexity= O(N*N) -- traversing in each row and coloumn so n*n
// space complexity- O(1) 

