#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define mod 1000000007

ll countWays(vector<int> nums,int n,int k,vector<vector<ll>>&dp) {

	// base case
	if(n == 0) {

		if(k == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	// look up step
	if(dp[n][k] !=-1) return dp[n][k];

	// self work........
	ll count = 0;
	for(int i = 0;i<=nums[n-1];i++) {
		if(k-i >= 0) {
			count = (count%mod + (ll)countWays(nums,n-1,k-i,dp)%mod)%mod;
		}
	} 
	return dp[n][k] = count;
}
// ll countWaysBU(vector<int> nums,int k) {
// 	int n = nums.size();
// 	vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
// 	// vector<vector<ll>> store(n+1,vector<ll>(k+1,0));

// 	dp[0][0] = 1;
// 	store[0][0] = 1;
// 	for(int i = 1;i<=n;i++){
// 		dp[i][0] = 1;
// 		// store[i][0] = 1; 
// 	}  
// 	for(int i = 1;i<=k;i++){
// 		dp[0][i] = 0;
// 		store[0][i] = 1;
// 	} 

// 	for(int i =1;i<=n;i++) {
// 		for(int j = 1;j<=k;j++) {
// 			ll idx = max(j-nums[i-1],0);
// 			dp[i][j] = (ll)(store[i-1][j]%mod - store[i-1][idx]%mod + dp[i-1][idx]%mod)%mod;
// 			store[i][j] = (ll)(store[i][j-1]%mod + dp[i][j]%mod)%mod; 

// 		}
// 	}
// 	return dp[n][k]%mod;
// }

ll countWaysBU(vector<int>& nums,int k) {
	int n = nums.size();
	vector<vector<ll>> dp(n,vector<ll>(k+1));

	for(int j = 0;j<=k;j++) {
		dp[0][j] = (j > nums[0])? 0 : 1;
	}
	for(int i = 0;i<n;i++) dp[i][0] = 1;
		
	for(int i = 1;i<n;i++) {
		for(int j = 1;j<=k;j++) {
			dp[i][j] = (mod + dp[i-1][j]%mod + dp[i][j-1]%mod - ((j-1-nums[i] >= 0)?dp[i-1][j-1-nums[i]]:0))%mod;
		}
	}
	return dp[n-1][k];
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
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
	cout << countWaysBU(nums,k) <<"\n";
}