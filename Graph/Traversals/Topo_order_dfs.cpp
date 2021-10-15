#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
const int N = 1e5 + 1;
vector<int> gr[N];
vector<int> order;

void dfs(int src,int par,vector<int>&visited) {

	visited[src] = 1;
	for(auto adj : gr[src]) {
		if(!visited[adj]) {
			dfs(adj,src,visited);
		}
	}
	order.push_back(src);
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
	vector<int> visited(n,0);
	while(m--) {
		int x,y;
		cin >> x >> y;
		gr[x].push_back(y);
	}
	for(int i =1;i<=n;i++) {
		if(!visited[i])
		  dfs(i,0,visited);
	}
	reverse(order.begin(),order.end());
	for(auto x : order) cout << x << " ";
}