#include<iostream>
#include<vector>

// Time complexity is O(n*logn).......
int ceilValue(std::vector<int>&dp,int x) {
	int n = dp.size();
	int low = 0;
	int high = n-1;
	int ans  = -1;
	while(low <= high) {
		int mid = low + (high-low)/2;

		if(dp[mid] <= x) {
			low =  mid+1;
		}
		else {
			ans = mid;
			high = mid-1;
		}
	}
	return ans;
}
int LIS(std::vector<int> nums,int n) {

	std::vector<int> dp;
	dp.push_back(nums[0]);

	for(int i = 1;i<n;i++) {

		if(nums[i] > dp[dp.size()-1]) {
			dp.push_back(nums[i]);
		}
		else {
			int idx = ceilValue(dp,nums[i]);
			dp[idx] = nums[i];
		}
	}
	for(int i : dp) std::cout << i << " ";
	return dp.size();
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

	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for(int i = 0;i<n;i++) std::cin>>nums[i];
	std::cout << LIS(nums,n) << "\n";
}