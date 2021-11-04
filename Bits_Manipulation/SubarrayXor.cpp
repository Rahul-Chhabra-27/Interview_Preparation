#include<bits/stdc++.h>

using namespace std;

int countSubarrays(int *nums,int n,int k) {
	
	unordered_map<int,int>map;
	map[0] = 1;
	int cnt = 0;
	int currXor = 0;
	for(int i = 0;i<n;i++) {
		currXor ^= nums[i];
		if(map.count(currXor^k)) {
			cnt += map[currXor^k];
		}
		map[currXor]++;
	}
	return cnt;
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

	int *nums = new int[n];

	for(int i = 0;i<n;i++) {
		int x;
		cin >> x;
		nums[i] = x;
	}
	cout << countSubarrays(nums,n,k);
	delete [] nums;
}