#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
const int N = 1e5+3;
int dp[N];

void primeFactorization() {

	for(int i = 2;i<=N-1;i++) {
		if(!dp[i]) {
			// this is a prime number..
			for(int j = 2*i;j<=N-1;j+=i) {
				dp[j]++;
			}
			dp[i] = 1;
		}
	}
	return;
}
int countKPrimes(int l,int r,int k) {
	int ans = 0;
	for(int i = l;i<=r;i++) {
		if(dp[i] == k) {
			ans++;
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

	int t;
	cin >> t;
	primeFactorization();
	while(t--) {
		int l,r,k;
		cin >> l >> r >> k;
		cout << countKPrimes(l,r,k) <<"\n";
	}
}