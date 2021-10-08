#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int minDistance(vector<vector<int>>&grid,vector<int>& source,vector<int>& des) {

	set<pair<int,pair<int,int>> set;
	// {dis , { x,y }}
	int n = grid.size();
	int m = grid[0].size();
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,1,-1};

	vector<int> dis(n*m+1,INT_MAX);
	set.insert({0,source[0],source[1]});

	while(!set.empty()) {
		auto currPosition = *set.begin();
		auto node = currPosition.second;
		int dis = currPosition.first;
		set.erase(currPosition);

		for(int i = 0;i<4;i++) {
			int xx = node.first;
			int yy = node.second;
			int ctn =0 ;

			while(xx >= 0 and yy >= 0 and xx < n and yy < m and !grid[xx][yy]) {
				ctn++;
				xx += dx[i];
				yy += dy[i];
			}
			ctn--;
			xx -= dx[i];
			yy -= dy[i];

			if(dis[])
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

}