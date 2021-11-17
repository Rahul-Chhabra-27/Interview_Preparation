#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define ll long long int
#define vvi vector<vector<int>>

// it will compute the manhattan dis bw every member.
vvi disCalculated(vector<pair<int,int>>A,vector<pair<int,int>>B) {
	int n = A.size();
	vvi ans(n,vector<int>(n));
	for(int i =0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			int xx = abs(A[i].first-B[j].first);
			int yy = abs(A[i].second-B[j].second);
			ans[i][j] = xx+yy;
		}
	}
	return ans;
}
int count_set_bit(int n) {
	int count =0;
	while(n > 0) {
		count++;
		n = (n&(n-1));
	}
	return count;
}
ll minDis(vvi store,int n) {
	
	vector<ll> dp((1<<n),INT_MAX);
	dp[0] = 0;
	for(int mask = 0;mask<(1<<n);mask++) {
		int currentHokageFighter = count_set_bit(mask);
		for(int j = 0;j<n;j++) {
			if(!((mask>>j)&1)) {
				dp[mask |(1<<j)] = min((dp[mask]+store[currentHokageFighter][j]),dp[mask|(1<<j)]);
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
	vector<pair<int,int>>A(n); // A->>Akatsuki member
	vector<pair<int,int>>B(n); // B->>Hokage member
	for(int i = 0;i<n;i++) {
		int x,y;
		cin >>x>>y;
		A[i] = {x,y};
	}
	for(int i = 0;i<n;i++) {
		int x,y;
		cin >> x >> y;
		B[i] = {x,y};
	}
	vvi store = disCalculated(A,B);
	cout << minDis(store,n) <<"\n";
}