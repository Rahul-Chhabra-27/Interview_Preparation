#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

const int N = 1e5;
vector<int> gr[N],grr[N];
int visited[N];

// TOPOLOGICAL SORT
void dfs(stack<int>& order,int src) {

	visited[src] = 1;
	for(int adj : gr[src]) {
		if(!visited[adj]) {
			dfs(order,adj);
		}
	}
	order.push(src);
}

// SIMPLE DFS
void dfs1(int src) {
	cout << src << " ";
	visited[src] = 1;
	for(int adj : grr[src]) {
		if(!visited[adj]) {
			dfs1(adj);
		}
	}
}
int KosaRaju(stack<int>& s) {
	int countSCC = 0;

	while(!s.empty()) {
		int curr = s.top();
		if(!visited[curr]) {
			countSCC++;
			dfs1(curr);
			cout << "\n";
		}
		s.pop();
	}
	return countSCC;
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
	std::cin >> n >> m;

	while(m--) {
		int x,y;
		cin >> x >> y;

		gr[x].push_back(y);
		grr[y].push_back(x);
	}
	stack<int> s;
	for(int i = 1;i<=n;i++) {
		if(!visited[i]) {
			dfs(s,i);
		}
	}
	memset(visited,0,sizeof(visited));
	int countSCC = KosaRaju(s);
	cout << "number of scc are ->>> " << countSCC <<"\n";
}