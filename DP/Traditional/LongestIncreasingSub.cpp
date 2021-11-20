#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int bestWay(vector<ll>& dp,ll el){
	int n = dp.size();
	int low = 0,high =n-1;
	int idx = -1;
	while(low <= high) {
		int mid = (low + (high-low)/2);

		if(dp[mid] < el) {
			low = mid+1;
		}
		else{
			idx = mid;
			high = mid-1;
		}
	}
	return idx;
}
ll LIS(vector<int>& nums) {
	int n = nums.size();
	vector<ll>dp;
	dp.push_back(nums[0]);
	for(int i = 1;i<n;i++) {

		if(dp[dp.size()-1] >= nums[i]) {
			int idx = bestWay(dp,nums[i]);
			dp[idx] = nums[i];
		}
		else{
			dp.push_back(nums[i]);
		}
	}
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
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	cout << LIS(nums)<<"\n";
}