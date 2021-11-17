#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long int
#define ff first
#define ss second

void floodFill(vector<vector<int>>& grid,int s,int e,int color) {

	if(color == grid[s][e]) return;
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	int n = grid.size();
	int m = grid[0].size();
	int legacyColor = grid[s][e];
	grid[s][e] = color;
	queue<pair<int,int>>q;
	q.push({s,e});
	while(!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		for(int i = 0;i<4;i++) {
			int xx= x+dx[i];
			int yy = y+dy[i];

			if(xx >= 0 and yy >= 0 and xx < n and yy < m and grid[xx][yy] == legacyColor) {
				grid[xx][yy] = color;
				q.push({xx,yy});
			}
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			cout << grid[i][j] << " ";
		}
		cout <<"\n";
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

	int t;
	cin >> t;
	while(t--) {
		int n,m;
	    cin >> n >> m;
	    vector<vector<int>> grid(n,vector<int>(m,0));
	    for(int i = 0;i<n;i++) {
	    	for(int j =0;j<m;j++) {
	    		cin >> grid[i][j];
	    	}
	    }
	    int s,e,color;
	    cin >> s >>e >> color;
	    floodFill(grid,s,e,color);
	}	

}