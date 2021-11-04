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

	string s1,s2;
	cin >> s1 >> s2;

	int n = s1.size(),m = s2.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {

			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = dp[n][m];
	string str(ans,' ');
	int i = n,j = m;

	while(i > 0  and j > 0) {

		if(s1[i-1] == s2[j-1]) {
			str[ans-1] = s1[i-1];
			i--;
			j--;
			ans--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout << str << "\n";
}