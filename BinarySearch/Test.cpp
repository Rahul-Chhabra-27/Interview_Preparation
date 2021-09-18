#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define log(arr) cout << (arr) <<"\n"

int findEl(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if(nums[mid] == x) {
			return mid;
		}
		else if(nums[mid] > x) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return -1;
}

int firstOccurence(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;
	int ans = -1;
	while(low <= high) {

		int mid = low + (high-low)/2;

		// found one occurence go left for better result....
		if(nums[mid] == x) {
			ans = mid;
			high = mid-1;
		} 
		else if(nums[mid] > x) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return ans;
}
int lastOccurence(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;
	int ans = -1;

	while(low <= high) {

		int mid = low + (high-low)/2;
		// found one occurence of x, now go right for better result....
		if(nums[mid] == x) {
			ans = mid;
			low = mid+1;
		}
		else if(nums[mid] > x) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return ans;
}
// upper bound means finding the  first element
// that is greater than x..
int upperBound(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;
	int ans = n;
	while(low <= high) {

		int mid = low + (high-low)/2;

		if(nums[mid] <= x) {
			low = mid+1;
		}
		else {
			ans = mid;
			high = mid-1;
		}
	}
	return ans;
}
// lower-bound means first element
// that is greater than or equals to x...
int lowerBound(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;
	int ans = n;

	while(low <= high) {

		int mid = low + (high-low)/2;

		if(nums[mid] >= x) {
			ans = mid;
			high = mid-1;
		}
		else  {
			low =  mid+1;
		}
	}
	return ans;
}

int countOccurences(vector<int>& nums,int n,int x) {

	int firstIdx = firstOccurence(nums,n,x);
	int lastIdx = lastOccurence(nums,n,x);
	if(firstIdx == -1) return 0;
	return lastIdx-firstIdx + 1;
}

// Time complexity will be O(log(n))
ll sqrtN(ll n) {

	ll low = 1,high = n;
	ll ans = 1;
	while(low <= high) {

		ll mid = low + (high-low)/2;

		if(mid*mid  == n) {
			return mid;
		}
		else if(mid*mid < n) {
			ans = mid;
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	return ans;
}

int minInRotated(vector<int>& nums,int n) {

	int low = 0,high = n-1;
	
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

int searchInSortedRotated(vector<int>& nums,int n,int x) {

	int low = 0,high = n-1;

	while(low <= high) {

		int mid = low + (high-low)/2;

		if(nums[mid] == x){
			return mid;
		}
		// check for first half
		else if(nums[low] <= nums[mid]) {
			
			if(x >= nums[low] and x < nums[mid]) {
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		// second half
		else{

			if(x > nums[mid] and x <= nums[high]){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
	}
	return -1;
} 

int findPeakElement(vector<int>& nums,int n){

	int low = 0,high= n-1;

	while(low < high) {

		int mid = low + (high-low)/2;

		if(nums[mid] > nums[mid+1]) {
			high = mid;
		}
		else {
			low = mid+1;
		}
	}
	return low;
}

bool searchInSortdRotated2(vector<int>& nums,int n,int k) {

    int low = 0,high = n-1;

    while(low <= high) {

        int mid = low + (high-low)/2;

        if(nums[mid] == k) {
            return true;
        }
        // special condition....
        if(nums[low] == nums[high] and nums[low] == nums[mid]) {
            high--;
            low++;
        }
        
        else if(nums[low] <= nums[mid]) {

            if(nums[low] <= k and nums[mid] > k) {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        else if(nums[mid] <= nums[high]) {

            if(nums[mid] < k and nums[high] >= k) {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
 }

 // int findMinInsortedRotatedArray(vector<int> nums,int n,int k) {


 // }

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	int n,k;
	cin >> n >> k;
	vector<int>nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	// log(findEl(nums,n,k));
    // log(firstOccurence(nums,n,k));
	// log(lastOccurence(nums,n,k));
	// log(upperBound(nums,n,k));
	// log(lowerBound(nums,n,k));
	// log(countOccurences(nums,n,k));
	// log(sqrtN(50));
	log(minInRotated(nums,n));
	// log(searchInSortedRotated(nums,n,k));
	// log(findPeakElement(nums,n));
	// log(searchInSortdRotated2(nums,n,k));
	// log(findMinInsortedRotatedArray(nums,n,k));
}