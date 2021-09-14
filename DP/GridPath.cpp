#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define mod 1000000007

ll totalWays(vector<vector<int> >& grid,int i,int j,int n,vector<vector<int> >& dp) {

	// base case
	if(i == n-1 and j == n-1 and grid[i][j]) {
		return 1;
	}
	// check for validation
	if(i >= n or j >= n or i < 0 or j < 0 or grid[i][j] == 0) {
		return 0;
	}
	
	// look up step
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// recursive intution
	ll totalPaths = (totalWays(grid,i+1,j,n,dp)%mod + totalWays(grid,i,j+1,n,dp)%mod)%mod;

	return dp[i][j] = totalPaths;
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
	cin >> n;
	vector<vector<int> > grid(n,vector<int>(n));
	vector<vector<int> > dp(n,vector<int>(n,-1));

	for(int i =0; i<n;i++) {
		for(int j = 0;j<n;j++) {
			char ch;
			cin >> ch;
			if(ch == '.'){
				grid[i][j] = 1; // 1 for empty cell.
			}
			else {
				grid[i][j] = 0; // 0 for blocked cell.
			}
		}
	}
	cout << totalWays(grid,0,0,n,dp) << "\n";
}