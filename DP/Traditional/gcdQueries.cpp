#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

void computeGcd(vector<int>& nums){
	int n = nums.size();
	vector<int>dp(n);
	dp[0] = nums[0];
	for(int i = 1;i<n;i++) {
		if((nums[i-1]%nums[i]) == 0) {
			dp[i] = nums[i];
		}
		else{
			cout << -1 << "\n";
			return;
		}
	}
	for(int el : dp) cout << el << " ";
	cout<<"\n";
	return;
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
		vector<int> nums(n);
		for(int i = 0;i<n;i++) cin >> nums[i];
		computeGcd(nums);
	}
}