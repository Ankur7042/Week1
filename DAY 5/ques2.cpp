#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity - O(size1 + size2)
Space complexity - O(1) - no extra space
*/

int main(){
    int size1,size2;
    vector<int>nums1(size1),nums2(size2);
    cout<<"Enter Size of nums1"<<endl;
    cin>>size1;
    cout<<"Enter Elements in nums1"<<endl;
    
    // Taking input from the user
    for(int i=0;i<size1;i++){
        cin>>nums1[i];
    }
    cout<<"Enter Size of nums2"<<endl;
    cin>>size2;
    cout<<"Enter Elements in nums2"<<endl;
    // Taking input frm the user 
    for(int i=0;i<size2;i++){
        cin>>nums2[i];
    }

// MARK :- variables for storing the index and value of median
// DESCRIPTION :- idx1 stores the index of first mid and first variable stores its value 
  //   idx2 stores the index of second mid and second variable stores its value
 int first,second,idx1,idx2;

 // updating idx1 and idx2 if total elments are even otherwise updating the idx1 if totalelements are odd
 if((size1 + size2)%2 == 0){
    idx1=(size1+size2)/2-1;
    idx2=(size1+size2)/2;
 }
 else{
    idx1=(size1+size2)/2;;
 }


//DESCRIPTION:- i and j are variables for traversing the nums1 and nums2 respectively 
//fill variable tell us i-th mninimum element
    int i=0,j=0,fill=0;
    while(i<size1 && j<size2){

        // if ith element is smaller or equal than the jth element
        if(nums1[i] <= nums2[j]){

//MARK:- updating the first and second variable
 /*DESCRIPTON:- 
 1. if size1 + size2 i.e totalElements are even then we will check that if we got the first mid index
  and second mid index then we will update it
 2. Otherwise if it is odd then we will update the first
*/
            if((size1 + size2)%2 == 0){
                if(fill == idx1) first=nums1[i];
                if(fill == idx2) {
                    second=nums1[i];
                    fill++;
                    break;
                }
            }
            if((size1 + size2)%2 == 1){
               if(fill == idx1) {
                    first=nums1[i];
                    fill++;
                    break;
                }
            }

          i++;
        }
        else{
//MARK:- updating the first and second variable
 /*DESCRIPTON:- 
 1. if size1 + size2 i.e totalElements are even then we will check that if we got the first mid index
  and second mid index then we will update it
 2. Otherwise if it is odd then we will update the first
*/
            if((size1 + size2)%2 == 0){
                if(fill == idx1) first=nums2[j];
                if(fill == idx2) {
                    second=nums2[j];
                    fill++;
                    break;
                }
            }
            if((size1 + size2)%2 == 1){
               if(fill == idx1) {
                    first=nums2[j];
                    fill++;
                    break;
                }
            }
      j++;
        }
      fill++;
    }


/*DESCRIPTION:-  if all elements of nums2 got over and now i is still less than nums1 size then we will traverse the whole
   nums1 and will update the variables as required
*/
    while(i<size1){
         if((size1 + size2)%2 == 0){
                if(fill == idx1) first=nums1[i];
                if(fill == idx2) {
                    second=nums1[i];
                    break;
                }
            }
            if((size1 + size2)%2 == 1){
               if(fill == idx1) {
                    first=nums1[i];
                    break;
                }
            }

          i++;
          fill++;
    }

/*DESCRIPTION:-  if all elements of nums1 got over and now j is still less than nums2 size then we will traverse the whole
   nums2 and will update the variables as required
*/
    while(j<size2){
          if((size1 + size2)%2 == 0){
                if(fill == idx1) first=nums2[j];
                if(fill == idx2) {
                    second=nums2[j];
                    break;
                }
            }
            if((size1 + size2)%2 == 1){
               if(fill == idx1) {
                    first=nums2[j];
                    break;
                }
            }
      j++;  
      fill++;
    }

   cout<<"Median is"<<endl;
    if((size1 + size2)%2 == 1) cout<< first;
    else cout<<(first+second)/2.0 ;


}