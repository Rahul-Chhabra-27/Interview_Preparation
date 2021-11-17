#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define ll long long int
#define mod 1000000009
const int N = 1e6;

ll dp[N];
int countWays(int x) {
	if(x<0) cout << -1 <<" ";
	// base case
	if(x == 0){
		return 1;
	}

	// look up step
	if(dp[x] != -1){
		return dp[x];
	}
	ll count = 0;

	if(x-2>=0){
		count = (count%mod + countWays(x-2)%mod)%mod;
	}
	if(x-3>=0){
		count = (count%mod + countWays(x-3)%mod)%mod;
	}
	return dp[x] = count;
}
ll countWaysBU(int x) {
	
	vector<ll> dp(x+1,0);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;
	for(int i = 3;i<=x;i++) {
		dp[i] = (dp[i-2]%mod + dp[i-3]%mod)%mod;
	}
	return dp[x];
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
		ll x;
		cin >> x;
		memset(dp,-1,sizeof(dp));
		cout << countWaysBU(x) << "\n";
	}
}