#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

/// gap traversal technique......
string lps(string str) {
	int n = str.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	int maxLen = 0;
	string ans = "";
	for(int g = 0;g<n;g++) {

		for(int i = 0,j = g;j<n;j++,i++) {

			if(g == 0) {
				dp[i][j] = 1;
			}
			else if(g == 1) {
				dp[i][j] = (str[i] == str[j])?2:0;
			}
			else{
				if(str[i] == str[j] and dp[i+1][j-1]) {
					dp[i][j] = dp[i+1][j-1]+2;
				}
			}

			if(dp[i][j] > maxLen) {
				maxLen = dp[i][j];
				ans = str.substr(i,(j-i)+1);
			}
		}
	}
	return ans;
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

	string str;
	cin >> str;
	cout << lps(str) << "\n";
}