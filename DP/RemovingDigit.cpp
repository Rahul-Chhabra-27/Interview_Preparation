#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minSteps(int n,vector<int>& dp) {

	// base case
	if(n < 10) {
		return 1;
	}

	// look up step
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive intution
	ll minDigitSteps = INT_MAX;
	int temp = n;
	while(temp > 0) {
		int digit = temp%10;
		
		// validation -->> to check if the digit is non-zero digit.
		if(digit != 0) {
			minDigitSteps = min(minDigitSteps,minSteps(n-digit,dp)+1);
		}
		temp /= 10;
	}

	return  dp[n] = minDigitSteps;
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
	vector<int> dp(n+1,-1);
	cout << minSteps(n,dp) <<"\n";
}