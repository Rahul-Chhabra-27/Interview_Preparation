#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define mod 1000000007

ll dp[55][1005];

ll countWays(int d,int s,int f) {

	// base case
	if(d == 0) {
		if(s == 0) {
			return 1;
		}
		else{
			return 0;
		}
	}

	// look up step...
	if(dp[d][s] != -1) return dp[d][s];
	ll count = 0;

	for(int i = 1;i<=f;i++) {
		if(s-i >= 0) {
			count = (count%mod + countWays(d-1,s-i,f)%mod)%mod;
		}
	}
	dp[d][s] = count;
	return count;
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

	int t;
	cin >> t;
	while(t--) {
		int d,f,s;
		memset(dp,-1,sizeof(dp));
		cin >> d >> f >> s;
		cout << countWays(d,s,f) << " ";
	}
}