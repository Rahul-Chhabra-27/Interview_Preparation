#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define log(arr) cout <<(arr) << "\n"
 
int findMin(vector<int>& nums,int n) {

	int low = 0;
	int high = n-1;

	while(low < high) {

		int mid = low + (high-low)/2;

		if(nums[mid] > nums[high]) {
			low = mid+1;
		}
		else {
			high = mid;
		}
	}
	return nums[low];
}
int findInSortedRotatedArray(vector<int>& nums,int n,int x) {

	int low = 0;
	int high = n-1;

	while(low <= high) {
		
		int mid = low + (high-low)/2;

		// check for mid element
		if(nums[mid] == x){
			return mid;
		}
		// for the second curve
		else if(nums[mid] <= nums[high]) {
			
			if(x > nums[mid] and x <= nums[high]) {
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		// for the first curve
		else {

			if(x < nums[mid] and x >= nums[low]) {
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
	}
	return -1;
}
int findInSortedRotatedArray2(vector<int> nums,int n,int x) {

	int low = 0;
	int high = n-1;
	while(low <= high) {

		int mid = low + (high-low)/2;

		if(nums[mid] == x){
			return mid;
		}
		else if(nums[low] == nums[high] and nums[low] == nums[mid]){
			high--;
			low++;
		}
		else if(nums[low] <= nums[mid]) {

			if(x >= nums[low] and x < nums[mid]) {
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		else{

			if(x > nums[mid] and x <= nums[high]) {
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
	}
	return -1;
}

int minElementInSortedRotatedArray2(vector<int>& nums,int n) {

	int low = 0;
	int high = n-1;

	while(low < high) {

		int mid = low + (high-low)/2;

		if(nums[mid] > nums[high]) {
			low = mid+1;
		}
		else if(nums[mid] < nums[high]) {
			high = mid;
		}
		else {
			high--;
		}
	}
	return nums[high];
}

int searchInBitonicArray(vector<int>& nums,int n,int k) {

	int low = 0,high = n-1;

	while(low <= high) {

		int mid = low + (high-low)/2;

		if(nums[mid] == k) {
			return mid;
		}
		// we are in the sorted half
		else if(nums[low] < nums[mid]) {

			if(k >= nums[low] and k < nums[mid]) {
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		else {
			if(k <= nums[low] and k > nums[mid]) {
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	int n,x;
	cin >> n >> x;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) {
		cin >> nums[i];
	}
	// log(findMin(nums,n));
	// log(findInSortedRotatedArray(nums,n,x));
	// log(findInSortedRotatedArray2(nums,n,x));
	// log(minElementInSortedRotatedArray2(nums,n));
	log(searchInBitonicArray(nums,n,x));
}