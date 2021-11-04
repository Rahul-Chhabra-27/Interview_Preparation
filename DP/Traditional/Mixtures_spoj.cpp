#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

using namespace std;

#define inf 1e18
#define ll long long int

ll dp[1005][1005];
ll sum[1005][1005];


ll minCost(vector<int>& nums,int i,int j) {

	// base case
	if(i == j){
		return 0;
	}

	// look up step
	if(dp[i][j] != -1) return dp[i][j];

	ll ans = inf;

	for(int k = i;k<j;k++) {
		ll firstSegment = minCost(nums,i,k);
		ll secondSegment = minCost(nums,k+1,j);
		ll total = (firstSegment + secondSegment + ((sum[i][k]%100)*(sum[k+1][j]%100)));
		ans = min(ans,total);
	}
	return dp[i][j] = ans;
}

void initializeSum(vector<int>& nums,int n) {
	for(int g = 0;g<n;g++) {
		for(int i = 0,j= g;j<n;i++,j++) {

			if(g == 0) {
				sum[i][j] = nums[i];
			}
			else{
				sum[i][j] = sum[i][j-1] + nums[j];
			}
		}
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
	while(scanf("%d",&n) != EOF) {
		vector<int> nums(n);
		for(int i = 0;i<n;i++) cin >> nums[i];
		memset(dp,-1,sizeof(dp));
		memset(sum,0,sizeof(sum));
		initializeSum(nums,n);
	    cout<<minCost(nums,0,n-1)<<"\n";
	}
}