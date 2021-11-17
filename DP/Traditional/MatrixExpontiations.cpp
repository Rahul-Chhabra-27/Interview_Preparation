#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	int n;
	cin >> n;
	int arr[n][n];
	ll store[n][n];
	memset(store,0,sizeof(store));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i<n;i++) {

		for(int j = 0;j<n;j++) {

			for(int k = 0;k<n;k++) {

				store[i][j] += (ll)(arr[i][k]*arr[k][j]); 
			}
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cout << store[i][j] << " ";
		}
		cout << "\n";
	}
}