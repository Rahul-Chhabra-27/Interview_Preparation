#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int minDistance(vector<vector<int>>&grid,vector<int>& source,vector<int>& destination) {

	set<pair<int,pair<int,int>>> set;
	// {dis , { x,y }}
	int n = grid.size();
	int m = grid[0].size();
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,1,-1};

	vector<int> dis(n*m+10,INT_MAX);
	dis[source[0]*m+source[1]] = 0;
	set.insert({0,{source[0],source[1]}});

	while(!set.empty()) {

		auto currPair = *set.begin();
		int disCurr = currPair.first;
		auto coords = currPair.second;
		set.erase(currPair);
		for(int i = 0;i<4;i++) {
			int xx = coords.first;
			int yy = coords.second;
			int cnt = 0;

			while(xx >= 0 and yy >= 0 and xx < n and yy < m and !grid[xx][yy]) {
				cnt++;
				xx += dx[i];
				yy += dy[i];
			}
			xx -=dx[i];
			yy -=dy[i];
			cnt--;

			if(dis[xx*m+yy] > cnt + disCurr) {
				dis[xx*m+yy] = cnt + disCurr;
				set.insert({dis[xx*m+yy],{xx,yy}});
			}
		}
	}
	return dis[destination[0]*m+destination[1]];
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
		for(int j = 0;j<m;j++) {
			cin >> grid[i][j];
		}
	}
	int x,y;
	cin >> x >> y;
	vector<int> source{x,y};
	cin >> x >> y;
	vector<int> destination {x,y};
	cout << minDistance(grid,source,destination) <<"\n";
}