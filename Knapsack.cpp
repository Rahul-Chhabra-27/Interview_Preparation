#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll knapsack(vector<ll>& weight,vector<ll>& prices,ll k,int i,ll n,vector<vector<ll> > dp) {

	// base case
	if(i == n) {
		return 0;
	}
	// look up step
	if(dp[i][k] != -1)
		return dp[i][k];

	// recusive intution
	ll pick = 0;
	ll unpick = 0;

	// check if this weight can avail itself for addition....
	if(weight[i] <= k) {
		pick = prices[i] + knapsack(weight,prices,k-weight[i],i+1,n,dp);
	}
	unpick = knapsack(weight,prices,k,i+1,n,dp);

	// self work
	return dp[i][k] = max(pick,unpick);
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

	ll n,k;
	cin >> n >> k;
	vector<ll> weight(n);
	vector<ll> prices(n);
	vector<vector<ll> > dp(n,vector<ll>(k+1,-1));
	for(int i = 0;i<n;i++) cin >> weight[i];
	for(int i = 0;i<n;i++) cin >> prices[i];
	cout << knapsack(weight,prices,k,0,n,dp) << '\n';
}