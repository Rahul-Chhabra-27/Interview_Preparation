#include<iostream>
#include<vector>
#include<climits>
#include<deque>
// #include<math.h>
// #include<stack>
// #include<queue>
// #include<set>
// #include<map>
// #include<unordered_map>
// #include<unordered_set>
// #include<list>

using namespace std;

const int N = 1e5;
vector<pair<int,int>> g[N];

void bfs(int src,int n) {
	
	vector<int> dis(n+1,INT_MAX);
	dis[src] = 0;
	deque<pair<int,int>> dq;
	dq.push_back({src,0});

	while(!dq.empty()) {
		int curr = dq.front().first;
		int dist = dq.front().second;
		dq.pop_front();
		for(auto adj : g[curr]) {

			if(dis[adj.second] > dis[curr] + adj.first) {
				dis[adj.second] = dist + adj.first;

				if(adj.first == 0) {
					dq.push_front({adj.second,dis[adj.second]});
				}
				else{
					dq.push_back({adj.second,dis[adj.second]});
				}
			}
		}
	}
	for(int i : dis) cout << i << " ";
	cout << "\n";

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
		int x,y,w;
		cin >> x >> y >> w;
		g[x].push_back({w,y});
		g[y].push_back({w,x});
	}
	bfs(1,n);
}