#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll maxPages(vector<int>pages,vector<int>cost,int x) {
	int n = pages.size();
	vector<vector<int>>dp(n+1,vector<int>(x+1,0));

	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=x;j++) {
			if(j-cost[i-1] >= 0) {
				dp[i][j] = max(dp[i][j],pages[i-1]+dp[i-1][j-cost[i-1]]);
			}
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
		}
	}
	return dp[n][x];
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

	int n,x;
	cin>> n>>x;
	vector<int> price(n);
	vector<int> pages(n);
	for(int i = 0;i<n;i++) cin >> price[i];
	for(int i = 0;i<n;i++) cin >> pages[i];
	cout << maxPages(pages,price,x)<<"\n";
}