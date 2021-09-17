#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

// Time complexity is O(n*log(n)).
ll countMinGondola(vector<ll>& nums,int n,int k) {

	sort(nums.begin(),nums.end()); /// n*log(n)
	int i = 0;
	int j = n-1;
	ll countGondola = 0;
	while(i < j) { // O(n)

		if(nums[i] + nums[j] <= k){
			++i;
		}
		--j;
		++countGondola;
	}
	if(i == j) {
		++countGondola;
	}
	return countGondola;
	// Total Complexity = n*log(n) + n -->>  O(n*log(n))...
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
	vector<ll> nums(n);
	for(int i= 0;i<n;i++) cin >> nums[i];
	cout << countMinGondola(nums,n,k) <<"\n";
}