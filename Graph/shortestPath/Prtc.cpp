#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

void helper(int& dp,int n) {

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(dp[i] == -1) dp[i][j] = 100;
		}
	}
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
	int dp[n][n];
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			int x;
			cin >> x;
			dp[i][j] = x;
		}
	}
	helper(dp,n);
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cout <<  dp[i][j] << " ";
		}
		cout <<"\n";
	}
	return 0;
}