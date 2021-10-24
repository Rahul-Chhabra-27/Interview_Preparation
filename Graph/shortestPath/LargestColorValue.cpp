#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int N = 1e5;
vector<int> gr[N];

int largestColorValue(string &colors,vector<int>indegrees) {

	int n = colors.size();
	int count = 0;
	vector<vector<int>> dp(n,vector<int>(26,0));
	queue<int>q;
	for(int i = 0;i<n;i++) {
		if(!indegrees[i]) {
			q.push(i);
			dp[i][colors[i]-'a'] = 1;
		}
	}
	while(!q.empty()) {
		int curr  = q.front();
		count++;
		q.pop();
		for(int adj : gr[curr]) {
			indegrees[adj]--;
			if(!indegrees[adj]) {
				q.push(adj);
			}
			for(int i = 0;i<26;i++) {

				if(colors[adj]-'a' == i) {
					dp[adj][i] = max(dp[adj][i],dp[curr][i]+1);
				}
				else{
					dp[adj][i] = max(dp[adj][i],dp[curr][i]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<26;j++) {
			ans = max(ans,dp[i][j]);
		}
	}
	return count == n ? ans : -1;
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
	string colors;
	cin >> colors;
	vector<int> indegrees(n);
	while(m--) {
		int x,y;
		cin >> x >> y;
		gr[x].push_back(y);
		indegrees[y]++;
	}
	cout << largestColorValue(colors,indegrees) << "\n";
}