#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

#define ll long long int
#define mod 1000000007

int binary[25][25];
int dp[(1<<25)];

int count_set_bits(int mask) {
	int count = 0;

	while(mask > 0) {
		count++;
		mask = (mask&(mask-1));
	}
	return count;
}
ll countWays(int mask,int n) {

	// base case 
	if(mask == ((1<<n)-1)) {
		return 1;
	}
	// look up step........
	if(dp[mask] != -1) return dp[mask];
	ll count = 0;

	for(int j = 0;j<n;j++) {
		int currentMen = count_set_bits(mask);
		if(!((mask >> j)&1) and binary[currentMen][j] == 1) {
			count = (count%mod +  countWays((mask|(1<<j)),n)%mod)%mod;
		}
	}
	return dp[mask] = count;
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
	memset(binary,0,sizeof(binary));
	memset(dp,-1,sizeof(dp));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin >> binary[i][j];
		}
	}
	cout << countWays(0,n)<<"\n";
}