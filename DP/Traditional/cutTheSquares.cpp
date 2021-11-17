#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minSquares(int n,int m) {
	// base case
	cout << n <<" "<<m <<"\n";
	if(n == m) return 1;
	if(n == 1 or m == 1) return n == 1?m:n;
	int ans = m/n;
	int a = m%n;
	int b = min(n,m);
	return ans + (minSquares(min(a,b),max(a,b))); 
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
		int n,m;
		cin >> n >> m;
		cout << minSquares(n,m)<<"\n";
	}
}