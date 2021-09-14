#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define mod 1000000007

ll countCombinations(ll n,vector<ll>& dp) {

	// base case
	if(n == 0){
		return 1;
	}

	// look up step
	if(dp[n] != -1){
		return dp[n];
	}

	//recursive intution
	ll countWays = 0;
	for(int i = 1;i<=6;i++) {
		if(n-i >= 0){
			countWays = (countWays%mod + countCombinations(n-i,dp)%mod)%mod;
		}
	}
	return dp[n] = countWays;
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

	ll n;
	cin >> n;
	vector<ll> dp(n+1,-1);
	cout << countCombinations(n,dp)<<'\n';
}