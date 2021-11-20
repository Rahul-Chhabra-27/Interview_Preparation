#include<iostream>
#include<vector>

using namespace std;

#define ll long long int
#define ff first
#define ss second

// 0 --> false sate , 1 --> winning state
int stringGame(int ones,int zeros,vector<vector<int>>& dp) {

	// base case
	if(ones == 0 or zeros == 0) {
		return 0;
	}
	// look up step...
	if(dp[ones][zeros] != -1) return dp[ones][zeros];

	int ans = stringGame(ones-1,zeros,dp) & stringGame(ones,zeros-1,dp);

	return dp[ones][zeros] = (ans == 0?1:0);
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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int ones = 0,zeros = 0;
		for(char ch : str) {
			if(ch == '0') zeros++;
			else ones++;
		}
		vector<vector<int>>dp(ones+1,vector<int>(zeros+1,-1));
		int ans = stringGame(ones,zeros,dp);
		if(ans == 1){
			cout << "Alice"<<"\n";
		}
		else{
			cout <<"Bob"<<"\n";
		}
	}
}