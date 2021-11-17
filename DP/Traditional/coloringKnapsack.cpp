#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll maxWeight(vector<vector<int>>& color,int m,int X,vector<vector<int>>& dp) {
	// base case
	if(m == 0) {
		return 0;
	}

	// look up step
	if(dp[m][X] != -2) {
		return dp[m][X];
	}
	int ans = -1;
	for(int wt: color[m-1]) {
		if((X-wt) >= 0) {
			int finalResult = maxWeight(color,m-1,X-wt,dp);
			if(finalResult != -1) {
				ans = max(ans,wt+finalResult);
			}
		}
	}
	return dp[m][X] = ans;
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

	int n,m,x;
	cin >> n >> m >> x;
	vector<vector<int>> colors(m);
	vector<int> wt(n);
	for(int i = 0;i<n;i++) cin >> wt[i];
	for(int i = 0;i<n;i++) {
		int x;
		cin >> x;
		colors[x-1].push_back(wt[i]);
	}
	vector<vector<int>> dp(m+1,vector<int>(x+1,-2));
	int ans = maxWeight(colors,m,x,dp);
	if(ans != -1) ans = x-ans;
	cout << ans << "\n"; 
}