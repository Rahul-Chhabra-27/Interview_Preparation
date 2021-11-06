#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

#define ll long long int


int count_set_bit(int mask) {
	int count = 0;
	while(mask > 0) {
		count++;
		mask = (mask&(mask-1));
	}
	return count;
}
ll minCost(vector<vector<ll>>& cost) {
	int n = cost.size();
	vector<ll> dp((1<<(n)),INT_MAX);
	dp[0] = 0;
	for(int mask = 0;mask<(1<<n);mask++) {
		int worker = count_set_bit(mask);
		for(int j = 0;j<n;j++) {
			
			if(((mask >> j)&1) == 0){
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)],dp[mask]+cost[worker][j]);
			}
		}
	}
	return dp[(1<<n)-1];
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

	vector<vector<ll>> cost(n,vector<ll>(n,0));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin >> cost[i][j];
		}
	}
	cout << minCost(cost) << "\n";
}