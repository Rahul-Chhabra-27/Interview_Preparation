#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

vector<bool> isPresent(int x) {
	vector<bool> ans(10,false);
	while(x>0) {
		int d = x%10;
		ans[d] = true;
		x/= 10;
	}
	return ans;
}
int longestSubsequence(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(10,0);
	int ans = 0;
	for(int i =0;i<n;i++) {
		int currentMax = 0;
		vector<bool> check = isPresent(nums[i]);
		for(int i = 0;i<10;i++) {
			if(check[i]) {
				currentMax = max(currentMax,dp[i]+1);
			}
		}
		for(int d = 0;d<10;d++) {
			if(check[d]) {
				dp[d] = currentMax;
			}
		}
		ans = max(ans,currentMax);
	}
	return ans;
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
	cout << longestSubsequence(nums)<<"\n";
}