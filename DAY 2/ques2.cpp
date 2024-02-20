#include<bits/stdc++.h>
using namespace std;

void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}


vector<vector<int>> tripletSum(vector<int> &arr, int target){
    // final vector that i will gonna return 
    vector<vector<int>>ans;
    for(int i=0;i<arr.size()-2;i++){
        int curr=arr[i];
        // new search space in which i will search for pair sum of target-curr
        int j=i+1,k=arr.size()-1;
        // remaining sum that i will find in the new search space
        int remaining = target-curr;
        // traversing on the new search space 
        while(j<k){
            // condition when we got the pair == remaining sum
            if(arr[j]+arr[k] == remaining){
                ans.push_back({curr,arr[j],arr[k]});
                j++;
                k--;
            }
            //if curr sum is less than remaining then we have to increase the sum so we will do j++
            else if(arr[j]+arr[k] < remaining) j++;
            // now sum is greater so we will decrease the sum so do k--
            else k--;
        }
    }
    return ans;
}

int main(){
    int n,target;
    cout<<"Enter targert"<<endl;
    cin>>target;
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
    MergeSort(arr, 0, n - 1);
    vector<vector<int>> ans =tripletSum(arr,target);

    // printing the triplets
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // if there is no triplets found 
    if(ans.size()==0) cout<<"NO Triplets found"<<endl;

}

// time complexity-0(N*N) --- for finding the triplets
// space complexity- O(N)-- taking new vector of size n while merging the sorted vectors