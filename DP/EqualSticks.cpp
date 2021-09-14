#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minMoves(vector<ll>& nums,int n) {

	if( n == 1 ){
		return 0;
	}
	else if( n == 2 ){
		return abs(nums[0]-nums[1]);
	}
	else {
		sort(nums.begin(),nums.end());
		ll minStick = 0;
		ll currentStick = n/2;
		for(int i = 0;i<n;i++) {
			if(i == currentStick) continue;
			minStick += abs(nums[currentStick]-nums[i]);
		}
		return minStick;
	}
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
	for(int i =0;i<n;i++)  cin>> nums[i];
	cout << minMoves(nums,n)<<'\n';
}