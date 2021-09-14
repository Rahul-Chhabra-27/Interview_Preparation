#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int editDistance(string s1,string s2, int n,int m,vector<vector<int> >& dp) {

	// base case
	if(n == 0){
		return  m;
	}
	if(m == 0){
		return n;
	}

	// look up step
	if(dp[n-1][m-1] != -1) {
		return dp[n-1][m-1];
	}

	if(s1[n-1] == s2[m-1]) {
		return dp[n-1][m-1] = editDistance(s1,s2,n-1,m-1,dp);
	}
	else {
		int deleteCh = editDistance(s1,s2,n-1,m,dp);
		int replaceCh = editDistance(s1,s2,n-1,m-1,dp);
		int addCh = editDistance(s1,s2,n,m-1,dp);
		return dp[n-1][m-1] = 1 + min(deleteCh,min(replaceCh,addCh));
	}
}
int editDistanceBU(string& s1,string& s2) {

	int n = s1.size();
	int m = s2.size();

	if(n == 0) {
		return m;
	}
	if(m == 0){
		return n;
	}

	vector<vector<int> >dp(n+1,vector<int>(m+1,0));

	for(int i = 0;i<=n;i++) {
		for(int j = 0;j<=m;j++) {

			if(i == 0) {
				dp[i][j] = j;
			}
			else if(j == 0) {
				dp[i][j] = i;
			}
			else if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			}
			else {
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
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

	string s1,s2;
	cin >>s1 >>s2;
	int n = s1.length();
	int m = s2.length();
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	cout << editDistanceBU(s1,s2) <<"\n";
}