#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll dp[1005][1005];
ll minCost(int n,int W,vector<int>&cost) {
	// base case
	if(n == 0) {

		if(W == 0) {
			return 0;
		}
		else{
			return INT_MAX;
		}
	}
	// look up step...
	if(dp[n][W] != -1) return dp[n][W];

	ll pick = INT_MAX;
	ll nonPick = INT_MAX;
	// check the availability of packet having weight n kg..
	if(cost[n-1] != -1 and (W-n) >= 0) {
		ll reqCost = minCost(n-1,W-n,cost);
		if(reqCost != INT_MAX){
			pick = cost[n-1] + reqCost;
		}
	}
	nonPick = minCost(n-1,W,cost);
	return dp[n][W] = min(nonPick,pick);
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

	int n,w;
	cin >> n >> w;
	vector<int> cost(n);
	for(int i = 0;i<n;i++) cin >> cost[i];
	memset(dp,-1,sizeof(dp));
	ll ans = minCost(n,w,cost);
	if(ans == INT_MAX) ans = -1;
	cout << ans << "\n";
}