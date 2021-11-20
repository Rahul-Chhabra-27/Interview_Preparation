#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

#define ll long long int

const int N = 501;
ll dp[N][N];

ll minCuts(int a,int b) {
	// base case
	if(a == b){
		return 0;
	}

	//look up step...
	if(dp[a][b] != -1) return dp[a][b];

	ll ans = INT_MAX;
	for(int x = 1;x<a;x++) {
		ans = min(ans,1+(minCuts(a-x,b)+minCuts(x,b)));
	}
	for(int y = 1;y<b;y++) {
		ans = min(ans,1+(minCuts(a,b-y)+minCuts(a,y)));
	}
	return dp[a][b] = ans;
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
	int a,b;
	cin >>a>>b;
	memset(dp,-1,sizeof(dp));
	cout << minCuts(a,b) <<"\n";
}