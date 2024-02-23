#include<bits/stdc++.h>
using namespace std;

/*
 Time Coplexity - O(N) - traversing the array once with 2 pointer approach so linear time complexity
 Space Complexity -O(1) - NO addtional space so constant space compelexity
*/

int main(){
    int length;
    cout<<"Enter length of array"<<endl;
    cin>>length;
    vector<int> height(length);
    cout<<"Enter the Array Values"<<endl;
    // Taking input from the user
    for(int i=0;i<length;i++){
        cin>>height[i];
    }
 
 // left and right pointers for traversal on array
    int left=0,right=length-1;
    int ans=0;
    while(left<right){

        // MARK :- calculating the area of present container
        //DESCRIPTION:- (right-left) is the length across the x-axis and min(height[left],height[right]) gives the
        // length across the y- axis i.e height
        int area= (right-left) * min(height[left],height[right]);

        // updating the ans
        ans=max(ans,area);

        // MARK :- updating the left or right pointer
        /*DESCRIRPTION :- now when we will decrease the length across the x-axis we expect to increase the 
         length across the y-axis .so we will move the pointer towards the side where the inital height is less 
         than the other*/
        if(height[left] < height[right]) left++;
        else right--;
    }

    cout<<"Maximum Water that can be stored is = " << ans<<endl;
}