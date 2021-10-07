#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

const int N = 1e5;
vector<int>G[N];
int indegree[N];

void topologicalOrder(int n) {
	queue<int> q;

	for(int i = 1;i<=n;i++) {
		if(!indegree[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {

		int currVer = q.front();
		cout << currVer << " ";
		q.pop();

		for(int adj : G[currVer]) {
			indegree[adj]--;

			if(!indegree[adj]) {
				q.push(adj);
			}
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
	while(m--) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		indegree[v]++;
	}
	topologicalOrder(n);
}