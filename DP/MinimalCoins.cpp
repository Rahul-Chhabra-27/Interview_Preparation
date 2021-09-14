#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minimalCoins(int n , ll sum, vector<ll>& coins,vector<ll>& dp) {

	// base case
	if(sum == 0){
		return 0;
	}

	// look up step....
	if(dp[sum] != -1){
		return dp[sum];
	}
	
	// recusive intution
	ll minCoins = INT_MAX;
	for(int i = 0;i<n;i++) {

		if(sum-coins[i] >= 0) {
			minCoins = min(minCoins,(minimalCoins(n,sum-coins[i],coins,dp)+1));
		}
	}
	return dp[sum] = minCoins;
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

	vector<ll> coins(n);
	vector<ll> dp(sum+1,-1);
	for(int i = 0;i<n;i++) cin >> coins[i];
	ll ans = minimalCoins(n,sum,coins,dp);
	if(ans == INT_MAX) {
		ans = -1;
	}
	cout <<  ans <<'\n';
}