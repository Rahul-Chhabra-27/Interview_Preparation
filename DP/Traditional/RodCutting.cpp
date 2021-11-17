#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll dp[102];
ll maxCost(int n,vector<int> nums) {

	// base case
	if(n == 0) {
		return 0;
	}
	// look up step..
	if(dp[n] != -1) return dp[n];
	ll maxCostAns = 0;

	for(int i = 1;i<=n;i++) {

		if((n-i) >= 0) {
			maxCostAns = max(maxCostAns,nums[i] + (maxCost(n-i,nums)));
		}
	}
	return dp[n] = maxCostAns;
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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> nums(n+1);
		memset(dp,-1,sizeof(dp));
		for(int i = 1;i<=n;i++) cin >> nums[i];
		cout << maxCost(n,nums) << "\n"; 
	}
}