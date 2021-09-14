#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minSum(vector<ll>& nums,int n) {
	ll currSum = 0;
	sort(nums.begin(),nums.end());

	for(int i = 0;i<n;i++) {

		if(currSum+1 >= nums[i]) {
			currSum += nums[i];
		}
		else{
			break;
		}
	}
	return currSum+1;
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
	int n;
	cin >> n;
	vector<ll> nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	cout << minSum(nums,n)<<"\n";
}