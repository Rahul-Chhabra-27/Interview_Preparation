#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

struct jobs{
	ll s,e,p;
};

bool cmp( jobs a, jobs b) {
	return a.e < b.e;
};

int bestWay(vector<jobs>& intervals,int s) {
	int n = intervals.size();
	int l = 0;
	int r = n-1;
	int idx = -1;
	while(l <= r) {
		int mid = (l+(r-l)/2);

		if(intervals[mid].e >= s) {
			r = mid-1;
		}
		else{
			idx = mid;
			l = mid + 1;
		}
	}
	return idx;
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
	vector<jobs> intervals(n);
	for(int i = 0;i<n;i++) {
		cin >> intervals[i].s >> intervals[i].e >> intervals[i].p;
	}
	sort(intervals.begin(),intervals.end(),cmp);
	vector<ll> dp(n,0);
	dp[0] = intervals[0].p;

	for(int i = 1;i<n;i++) {
		ll st = intervals[i].s;
		int idx = bestWay(intervals,st); 
		if(idx != -1) {
			dp[i] = max(dp[i-1],dp[idx]+intervals[i].p);
		}
		else{
			dp[i] = max(dp[i-1],intervals[i].p);
		}
	}
	cout << dp[n-1] <<"\n";
}