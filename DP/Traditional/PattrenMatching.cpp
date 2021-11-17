#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

bool isMatching(string s1,string s2) {

	string str = "";
	int n = s1.size(); // pattern length.
	int m = s2.size(); // string length.
	for(int i = 0;i<n;i++) {
		if(s1[i] == '*') continue;
		if(s1[i+1] == '*') {
			if(s1[i] == '.'){
				str += "$";
			} else{
				str += toupper(s1[i]);
			}
		}
		else {
			str += s1[i];
		}
	}
	s1 = str;
	n = s1.size();
	cout << s1 << " ";
	bool dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[0][0] = true;
	for(int i = 1;i<=m;i++) dp[0][i] = false;
	for(int i = 1;i<=n;i++) {
		if(isupper(s1[i-1]) or s1[i-1] == '$') {
			dp[i][0] = dp[i-1][0];
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {

			// dot(.) character
			if(s1[i-1] == '.') {
				dp[i][j] = dp[i-1][j-1];
			}
			// $(dollar) character
			else if(s1[i-1] == '$') {
				dp[i][j] = dp[i-1][j] or dp[i][j-1];
			}
			// UPPERCASE character or * character
			else if(isupper(s1[i-1])) {
				dp[i][j] = dp[i-1][j];
				int ch = tolower(s1[i-1]);
				if(ch == s2[j-1]) {
					dp[i][j] = dp[i][j] || dp[i][j-1];
				}
			}
			// simple character
			else{
				dp[i][j] = s1[i-1] == s2[j-1]?dp[i-1][j-1]:0;
			}
		}
	}
	return dp[n][m];
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
	string n,m;
	cin >> n >> m;
	cout << isMatching(n,m) <<"\n";
}