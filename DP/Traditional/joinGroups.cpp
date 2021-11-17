#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define inf 1e15

ll dp[12][1<<12];
ll minCost(vector<vector<int>>& cost,int i, int mask,int m) {

	// base case
	if(i == -1) {
		// all the members of grp1 are explored..
		if(mask == (1<<m)-1) {
			// all the members of grp2 are explored..
			return 0;
		}
		else{
			return inf;
		}
	}

	if(dp[i][mask] != -1) return dp[i][mask];

	ll ans = inf;
	for(int j =0;j<m;j++) {

		ans = min(ans,cost[i][j]+minCost(cost,i-1,(mask|(1<<j)),m));

		if(!(mask&(1<<j))) {
			ans = min(ans,cost[i][j]+minCost(cost,i,(mask|(1<<j)),m));
		}
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

	int t;
	cin >> t;

	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<vector<int>> cost(n,vector<int>(m));
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				cin >> cost[i][j];
			}
		}
		memset(dp,-1,sizeof(dp));
		cout << minCost(cost,n-1,0,m)<<"\n";
	}
}