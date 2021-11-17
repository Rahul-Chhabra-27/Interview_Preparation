#include<bits/stdc++.h>

using namespace std;

#define ll long long int

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
	cin >>t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0;i<n;i++) {
			cin >> nums[i];
		}
		int oneKeep = 0;
		int elKeep = 0;

		for(int i = 1;i<n;i++) {
			int tempOneKeep = max((elKeep+abs(1-nums[i-1])),oneKeep);
			int tempElKeep = max((elKeep + abs(nums[i]-nums[i-1])),(oneKeep+abs(nums[i]-1)));
            oneKeep = tempOneKeep;
            elKeep = tempElKeep;
		}
		cout << max(oneKeep,elKeep) << "\n";
	}
}