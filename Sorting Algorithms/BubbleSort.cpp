#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second


void BubbleSort(int *nums,int n) {

	for(int i = 0;i<n;i++) {

		bool isSorted = true;

		for(int j = 0;j<n-i-1;j++) {

			if(nums[j] > nums[j+1]){
				swap(nums[j],nums[j+1]);
				isSorted = false;
			}
		}
		if(isSorted){
			break;
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

	int *nums = new int[n];
	for(int i = 0;i<n;i++) cin >> nums[i];
	BubbleSort(nums,n);
	for(int i = 0;i<n;i++) {
		cout << nums[i] << " ";
	}
	
}