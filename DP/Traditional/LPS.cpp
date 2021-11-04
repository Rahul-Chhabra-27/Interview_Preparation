#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	string str;
	cin >> str;

	int n = str.size();

	vector<vector<int>> dp(n,vector<int>(n,0));

	for(int g = 0;g<n;g++) {

		for(int i = 0,j = g;j<n;i++,j++) {

			if(g == 0){
				dp[i][j] = 1;
			}
			else if(g == 1) {
				dp[i][j] = str[i] == str[j] ? 2 : 1;
			}
			else{
				if(str[i] == str[j]) {
				    dp[i][j] = 2 + dp[i+1][j-1];
			    }
				else{
					dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
				}
			}
		}
	}
	cout<<dp[0][n-1]<<"\n";
}