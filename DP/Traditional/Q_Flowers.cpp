#include<iostream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;

#define ll long long int


struct flowers {
	int h;
	int b;
};
ll maxCost(vector<flowers>& nums) {
	int n = nums.size();
	vector<ll> dp(n,0);
	map<ll,ll> map;
	map[nums[0].h] = nums[0].b;
	dp[0] = nums[0].b;
	ll ans = dp[0];

	for(int i = 1;i<n;i++) {
		int h = nums[i].h;
		int cost = nums[i].b;
		dp[i] = cost;
		auto it = map.lower_bound(h);

		if(it != map.begin()){
			it--;
			dp[i] += map[it->first];
		}
		map[h] = dp[i];
		it = map.upper_bound(h);
		while(it != map.end() and map[it->first] <= dp[i]) {
			auto t = it;
			t++;
			map.erase(it);
			it = t;
		}
		ans = max(ans,dp[i]);
	}
	return ans;
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
	cin>>n;

	vector<flowers> nums(n);

	for(int i = 0;i<n;i++) {
		cin >> nums[i].h;
	}
	for(int i = 0;i<n;i++) {
		cin >> nums[i].b;
	}
	cout << maxCost(nums) << "\n";
}