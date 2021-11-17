#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int visited[1000005];
bool ans = true;
void canColour(vector<vector<int>>& gr,int node,int par,int color) {

	visited[node] = color;

	for(int adj : gr[node]) {
		// not visted
		if(!visited[adj]) {
			canColour(gr,adj,node,3-color);
		}
		else if(adj != par and color == visited[adj]) {
			ans = false;
		}
	}
	return; 
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
	vector<vector<int>>gr(n);
	while(m--) {
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	canColour(gr,0,-1,1);
	cout << ans << "\n";
}