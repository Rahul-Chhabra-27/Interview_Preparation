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
		int n = 7;
		vector<int> nums(n);
		for(int i =0;i<n;i++) cin >> nums[i];

		int countSunny = 0;
		for(int i =0;i<n;i++) {
			// sunny day
			if(nums[i] == 1){
				countSunny++;
			}
			else{
				countSunny--;
			}
		}
		string ans = countSunny > 0?"YES":"NO";
		cout << ans <<"\n";
	}
}