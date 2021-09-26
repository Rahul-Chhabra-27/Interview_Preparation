#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second
#define log(arr) cout << (arr) <<"\n"

void lovely(vector<int>& nums,int n) {

	int count_even = 0;
	int count_odd = 0;
	for(int i = 0;i<n;i++) {
		// for odd element
		if(nums[i]&1){
			count_odd++;
		}
		else{
			count_even++;
		}
	}

	if(abs(count_even-count_odd) <= 1){
		vector<int> odd;
		vector<int> even;

		for(int i = 0;i<n;i++) {
			if(nums[i]&1){
				odd.push_back(nums[i]);
			}
			else{
				even.push_back(nums[i]);
			}
		}
		int i = 0;
		int len = min(odd.size(),even.size());
		vector<int> ans;
		if(odd.size() < even.size()) {
			ans.push_back(even[even.size()-1]);
		}
		while(i < len) {
			ans.push_back(odd[i]);
			ans.push_back(even[i]);
			i++;
		}
		if(odd.size() > even.size()) {
			ans.push_back(odd[odd.size()-1]);
		}
		for(int i : ans) cout << i << " ";
		cout << "\n";
	}
	else{
		log(-1);
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

	int t;
	cin >> t;

	while(t--) {

		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0;i<n;i++) cin >> nums[i];
		lovely(nums,n);
	}
}