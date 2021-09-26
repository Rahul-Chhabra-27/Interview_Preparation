#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

string predictWinner(ll n) {

	vector<int> dp(n+1,false);
	dp[0] = false;
	dp[1] = true;
	for(int i = 2;i<=n;i++) {

		if(i&1) {
			dp[i] = !dp[i-1];
		}
		else{
			ll curr = 2;
			while(i >= curr) {
				if(n%curr == 0 and dp[i/curr] == false) {
					dp[i] = true;
					break;
				}
				else{
					curr = curr*2;
				}
			}
			if(dp[i] == false) {
				dp[i] = !dp[i-1];
			}
		}
	}
	
	if(dp[n]){
		return "Alice";
	}
	else{
		return "Bob";
	}
}
int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		// freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << predictWinner(n) <<'\n';
	}
}