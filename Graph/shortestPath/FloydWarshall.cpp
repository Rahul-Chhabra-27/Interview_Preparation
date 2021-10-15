#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define longVal INT64_MAX

void helper(vector<vector<ll>>& graph,int n) {

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(graph[i][j] == -1){
				graph[i][j] = (longVal/2)-1;	
			} 
		}
	}
	return;
}
// Time compelxity is O(n^3);
void floyd_warshall(vector<vector<ll>>&graph,int n) {

	for(int k =0;k<n;k++) {

		for(int i = 0;i<n;i++) {

			for(int j = 0;j<n;j++) {

				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
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
	int n;
	cin >> n;

	vector<vector<ll>> graph(n,vector<ll>(n));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin >> graph[i][j];
		}
	}
	helper(graph,n);
	floyd_warshall(graph,n);
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cout << graph[i][j] <<" ";
		}
		cout <<"\n";
	}
}