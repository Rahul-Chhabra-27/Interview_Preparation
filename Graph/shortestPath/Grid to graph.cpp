#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<vector<int>> gridToGraph(vector<vector<int>>&grid,int n,int m) {

	vector<vector<int>>G(n*m+1);

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {

			int currentVer = i*m+j;

			for(int k =0;k<4;k++) {
				int xx = i+dx[i];
				int yy = j+dy[i];

				if(xx >= 0  and yy >= 0 and xx < n  and yy < m ) {
					int nextPos = xx*m+yy;
					
				}
			}
		}
	}
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

	int n,m;
	cin >> n >> m;

	vector<vector<int>> grid(n,vector<int>(m));
	for(int i = 0;i<n;i++) {

		for(int j = 0;j<n;j++) {

			cin >> grid[i][j];
		}
	}
}