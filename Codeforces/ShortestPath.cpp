#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second


void shorestPath(vector<pair<int,int>> G[],int n) {
	set<pair<int,int>> set;
	vector<int> dis(n+1,INT_MAX);
	vector<int> parent(n+1,-1);
	set.insert({0,1});
	dis[1] = 0;
	while(!set.empty()) {

		auto currVer = *set.begin();
		set.erase(currVer);
		int ver = currVer.second;
		int disCurr = currVer.first;

		for(auto adj : G[ver]) {

			if(dis[adj.second] > disCurr + adj.first) {
				parent[adj.second] = ver;
				dis[adj.second] = disCurr + adj.first;
				set.insert({dis[adj.second],adj.second});
			}
		}
	}
	if(parent[n] != -1){
		vector<int> path;
		int temp = n;
		while(temp != -1) {
			path.push_back(temp);
			temp = parent[temp];
		}
		reverse(path.begin(),path.end());
		for(int i : path) cout << i << " ";
			cout << "\n";
	}
	else{
		cout << -1 <<"\n";
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
	vector<pair<int,int>>G[n+1];
	while(m--) {
		int u,v,w;
		cin >> u >> v >> w;
		if(u == v) continue;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	shorestPath(G,n);
}