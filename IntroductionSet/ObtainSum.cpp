#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll findIndexBS(ll n,ll k,ll sum) {

	int start = 1;
	int end = n;

	while(start <= end) {

		ll mid = start+(end-start)/2;
		// cout << mid << endl;
		if((sum-mid) == k) {
			return mid;
		}
		else if((sum-mid) > k) {
			start = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	return -1;
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

	ll t;
	cin >> t;
	while(t--) {
		ll n, s;
		cin >> n >> s;
		ll sum = (n*(n+1))/2;
		cout << findIndexBS(n,s,sum) <<"\n";
	}
}