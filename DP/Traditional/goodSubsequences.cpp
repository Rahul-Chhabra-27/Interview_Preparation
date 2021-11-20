#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define mod 1000000007.

ll totalCombinations(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n+1);
	unordered_map<int,int>map;
	for(int i = 0;i<n;i++) {
		if(!map.count(nums[i])) map[nums[i]] = i+1;
	}
	dp[0] = 1;
	dp[1] = 2;

	for(int i = 2;i<=n;i++) {
		if(nums[i-1] != nums[i-2]) {
			dp[i] = dp[i-1]*2;
		}
		else{
			int idx = map[nums[i-1]];
			dp[i] = (2*dp[idx-1]-dp[idx-1]) + dp[i-1];
		}
	}
	return dp[n];
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

	int n,k;
	cin >> n>>k;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) {
		cin >> nums[i];
	}
	cout << totalCombinations(nums)<<"\n";
}