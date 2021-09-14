#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define mod 1000000007

ll countCombinationsBU(vector<int>& nums,int sum) {

	int n = nums.size();
	vector<ll> dp(sum+1,0);
	dp[0] = 1;
	for(int i = 0;i<n;i++) {

		for(int j = nums[i];j<= sum;j++) {

			dp[j] = (dp[j]%mod + dp[j-nums[i]]%mod)%mod;
		}
	}
	return dp[sum];
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
	int sum;
	cin >> n >> sum;
	vector<int> nums(n);
	for(int i =0;i<n;i++) {
		cin >> nums[i];
	}
	cout << countCombinationsBU(nums,sum)<<"\n";
}