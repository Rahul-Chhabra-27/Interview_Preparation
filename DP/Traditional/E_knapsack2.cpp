#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;
// if(val[i] > j) {
// 				dp2[j] = dp1[j];
// 			} else {
// 				dp2[j] = min({dp2[j], dp1[j], wt[i] + dp1[j-val[i]]});
// 			}

int knapVariation(vector<int>& nums,vector<int>& wt,int n,int k) {

	vector<ll> dp1(n*1000+1,INT_MAX);
	vector<ll> dp2(n*1000+1,INT_MAX);

	dp1[0] = 0;
	dp1[nums[0]] = wt[0];
	for(int i = 1;i<=n-1;i++) {

		for(int j = 0;j<=n*1000;j++) {

			if(nums[i] > j){
				dp2[j] = dp1[j];
			}
			else{
				dp2[j] = min({dp2[j],dp1[j],wt[i] + dp1[j-nums[i]]});
			}
		}
		
		for(int i = 0;i<=n*1000;i++) {
			dp1[i] = dp2[i];
			dp2[i] = INT_MAX;
		}
		
	}
	int result = 0;
	for(int i = 0;i<=n*1000;i++) {
		// cout << dp1[i] << " ";
		if(dp1[i] <= k) result = i;
	}
	return result;
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
	vector<int> wt(n);

	for(int i = 0;i<n;i++) {
		cin >> wt[i] >> nums[i];
	}
	cout << knapVariation(nums,wt,n,k)<<" ";
}