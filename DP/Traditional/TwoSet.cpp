#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

#define ll long long int

#define mod 1000000007

ll dp[501][70000];

ll countWaysBU(ll n,ll sum) {
	vector<vector<ll>>dp(n+1,vector<ll>(sum+1,0));
	dp[0][0] = 1;
	for(int i = 1;i<=n;i++) {
		for(int j = 0;j<=sum;j++) {
			dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod)%mod;
			
			if(j-i >= 0) {
				dp[i][j] = (dp[i][j]%mod + dp[i-1][j-i]%mod)%mod;
			}
		}
	}
	return (dp[n][sum]*500000004)%mod;
}
ll countWaysTD(ll n,ll sum) {

	// base case
	if(sum == 0){
		return 1;
	}
	if(n == 0) return 0;

	// look up step
	if(dp[n][sum] != -1) return dp[n][sum];

	ll count = 0;

	if(sum-n >= 0) {
		count = (count%mod + countWaysTD(n-1,sum-n)%mod)%mod;
	}
	count = (count%mod + countWaysTD(n-1,sum)%mod)%mod;

	return  dp[n][sum] = count;
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
	ll sumUpToN = ((ll)n*(n+1))/2;
	memset(dp,-1,sizeof(dp));
	ll ans = 0;
	cout << countWaysBU(n,sumUpToN/2) << "\n";
	if(sumUpToN&1){
		cout << ans << "\n";
	}
	else{
		ll ans = (countWaysTD(n,sumUpToN/2)*500000004)%mod;
	    cout << ans << "\n";
	}
}