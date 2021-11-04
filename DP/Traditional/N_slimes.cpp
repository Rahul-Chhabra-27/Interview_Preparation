#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define inf  1e18

ll dp[405][405];
ll sum[405][405];

ll minSlimes(vector<int>& nums,int i,int j) {

	// base case 
	if(i == j) {
		return 0;
	}
	// look up step
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	ll minCost = inf;
	for(int k = i;k<j;k++) {
		minCost = min((minSlimes(nums,i,k)+minSlimes(nums,k+1,j)+sum[i][j]),minCost);
	}
	return dp[i][j] = minCost;
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
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++) cin >> nums[i];
	memset(dp,-1,sizeof(dp));
	memset(sum,0,sizeof(sum));
	initializeSum(nums,n);
	cout << minSlimes(nums,0,n-1)<<"\n";
}