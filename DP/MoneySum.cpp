#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

void moneySum(vector<int>& nums,int n) {

	set<int> container;
	container.insert(nums[0]);
	for(int i = 1;i<n;i++) {
		set<int> temp;
		for(int x : container) {
			temp.insert(x+nums[i]);
		}
		container.insert(nums[i]);
		container.insert(temp.begin(),temp.end());
	}
	cout << container.size() <<"\n";
	for(int x : container) cout << x << " ";
	cout <<'\n';

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
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		nums[i] = x;
	}
	moneySum(nums,n);
}