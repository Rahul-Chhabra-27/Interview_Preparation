#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define ll long long int
#define mod 1000000007

vector<int> gr[100005];
ll dp[100005][2];

ll countWays(int node,int parent,int c) {

	// look up step
	if(dp[node][c] != -1) return dp[node][c];

	ll count = 0;
	ll w0 = 1;
	ll w1 = 0;
	for(int child : gr[node]) {
		if(child != parent) {
			w0 = ((w0%mod) *(countWays(child,node,0)%mod))%mod;
		}
	}
	count = (count%mod + w0%mod)%mod;

	if(!c) {
		w1 = 1;
		for(int child : gr[node]) {
			if(child != parent) {
				w1 = ((w1%mod) *(countWays(child,node,1)%mod))%mod;
			}
	    }
	}
	count = (count%mod + w1%mod)%mod;
	return dp[node][c] = count;
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
	memset(dp,-1,sizeof(dp));
	for(int i = 1;i<=n-1;i++) {
		int x,y;
		cin >> x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	cout << countWays(1,-1,0)<<"\n";
}