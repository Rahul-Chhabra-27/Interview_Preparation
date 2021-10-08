#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int position(vector<int>& nums,int idx,int value) {

	int j = idx;
	while(j >= 0 and nums[j] > value) {
		nums[j+1] = nums[j];
		j--;
	}
	return j+1;

}
void InsertionSort(vector<int>& nums,int n) {

	for(int i = 1;i<n;i++) {
		int value = nums[i];
		int idx = position(nums,i-1,value);
		nums[idx] = value;
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
	InsertionSort(nums,n);
	for(int i : nums) cout << i <<" " ;

}