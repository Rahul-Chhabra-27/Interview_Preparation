#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

bool isSubsetExists(vector<int>& nums,int k,int i,int n) {

	// base case
	if(k == 0) {
		return true;
	}
	if(i == n) {
		return false;
	}
	bool pick = false;
	bool unpick =  false;
	// recusive intution
	if(k >= nums[i]) {
		pick = isSubsetExists(nums,k-nums[i],i+1,n);
	}

	unpick = isSubsetExists(nums,k,i+1,n);

	return (pick || unpick); 
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

	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	cout << isSubsetExists(nums,k,0,n) <<"\n";
}