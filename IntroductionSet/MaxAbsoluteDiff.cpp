#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll maxDiff(int n,int s) {

	int start = 0;
	int end = n;
	ll maxDiff = 0;
	while(start < end) {

		if(start+end == s) {
			maxDiff = max(maxDiff,(ll)abs(start-end));
			end--;
		}
		else if((start+end) > s) {
			end--;
		}
		else {
			start++;
		}
	}
	return maxDiff;
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
		int n,s;
		cin >> n >> s;
		cout << maxDiff(n,s) <<"\n";
	}
}