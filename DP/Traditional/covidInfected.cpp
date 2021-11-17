#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int minTime(vector<vector<int>>& area,int n,int m) {
	int dx[] = {-1,1,0,0}; // udrl
	int dy[] = {0,0,1,-1};
	queue<pair<int,int>> q;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			if(area[i][j] == 2){
				area[i][j] = 0;
				q.push({i,j});
			}
		}
	}
	q.push({-1,-1});
	int ans = 0;
	while(q.size() > 1) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		if(x == -1 and y == -1) {
			ans++;
			q.push({-1,-1});
			continue;
		}
		for(int i = 0;i<4;i++) {
			int xx = x+dx[i];
			int yy = y+dy[i];

			if(xx >= 0 and yy >= 0 and xx < n and yy < m and area[xx][yy] == 1) {
				area[xx][yy] = 0;
				q.push({xx,yy});
			}
		}

	}
	for(int i =0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			if(area[i][j] == 1){
				return -1;
			}
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
		vector<vector<int>>area(n,vector<int>(m,0));

		for(int i = 0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				cin >> area[i][j];
			}
		}
		cout << minTime(area,n,m)<<"\n";
	}
}