#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minRounds(vector<ll>& nums,int n) {

	if(n == 1) return 1;

	ll h = nums[0];
	ll rounds = 1;
	ll l = 0;
	for(int i =1;i<n;i++) {

		if(nums[i] > h){
			h = nums[i];
		}
		else if(nums[i] < h and rounds == 1){
			l = nums[i];
			rounds++;
		}
		else if(nums[i] > l) {
			l = nums[i];
		}
		else {
			l = nums[i];
			rounds++;
		}

	}
	return rounds;
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
	cout << minRounds(nums,n) <<"\n";
}