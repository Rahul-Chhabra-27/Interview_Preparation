#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define mod 1000000007

ll countWays(int n,ll sum,vector<int>& coins,vector<ll>& dp) {

	// base case
	if(sum == 0){
		return 1;
	}

	// look up step...
	if(dp[sum] != -1) {
		return dp[sum];
	}

	//recusive intution
	ll count = 0;
	for(int i = 0;i<n;i++) {
		if(sum-coins[i] >= 0){
			count = (count%mod + countWays(n,sum-coins[i],coins,dp)%mod)%mod;
		}
	}
	return dp[sum] = count;
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
	ll sum;
	cin >> n >> sum;
	vector<int> coins(n);
	for(int i = 0;i<n;i++) {
		cin >>coins[i];
	}
	vector<ll> dp(sum+1,-1);
	cout << countWays(n,sum,coins,dp) <<"\n";
}