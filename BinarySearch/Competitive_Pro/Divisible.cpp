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

	int t;
	cin >> t;

	while(t--) {

		int n;

		cin >> n;

		if(n == 1){
			cout << 3 <<"\n";
		}
		else if(n == 2){
			cout << "15" <<'\n';
		}
		else{
			
			string ans = "3";

			for(int i = 0;i<n-2;i++) {
				ans += "0";
			}
			ans += "3";
			cout << ans <<"\n";
		}
	}
}