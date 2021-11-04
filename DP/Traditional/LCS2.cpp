#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	string s1;
	cin >> s1;
	int n = s1.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	string s2 = s1;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {

			if(s1[i-1] == s1[j-1] and i != j) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	cout << dp[n][n] << "\n";
}