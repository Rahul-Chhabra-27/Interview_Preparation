#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll dp[105][105];
vector<int> dx{1,1,1};
vector<int> dy{1,-1,0};

ll maxCoins(pair<int,int>end,vector<vector<int>>& grid,int i,int j,int n,int m) {

	// base case
	if(i == end.ff and j == end.ss) {
		ll val = grid[i][j];
		return val;
	}
	// boundary conditions....
	if(i < 0 or j < 0 or i >= n or j >= m) {
		return 0;
	}
	// look up step...
	if(dp[i][j] != -1) return dp[i][j];
	
	ll currentCost = grid[i][j];
	ll ans = 0;
	for(int x = 0;x<3;x++) {
		int xx = i+dx[x];
		int yy = j+dy[x];
		ans = max(ans,maxCoins(end,grid,xx,yy,n,m));
	}
	return dp[i][j] = ans + currentCost;
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
		vector<vector<int>> grid(n,vector<int>(m,0));
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i<n;i++) {
			for(int j =0;j<m;j++) {
				cin >> grid[i][j];
			}
		}
		pair<int,int> end = {n-1,0};
		cout << maxCoins(end,grid,0,0,n,m) <<"\n";

		for(int i =0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				cout << grid[i][j] << " ";
			}
			cout<<"\n";
		}
	}
}