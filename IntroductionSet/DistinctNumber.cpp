#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int countDistinct(vector<ll>& nums,int n) {

	// sort the vector
	sort(nums.begin(),nums.end());
	
	ll distinctNumbers = 1;
	for(int i =0;i<n-1;i++) {
		if(nums[i] != nums[i+1]) distinctNumbers++;
	}
	return distinctNumbers;
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
	for(int i =0;i<n;i++) cin >> nums[i];
	cout << countDistinct(nums,n) <<'\n';
}