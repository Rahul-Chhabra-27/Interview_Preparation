#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

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
		ll left;
		ll right;
		cin >> left >> right;
		int range = 3;
		// go till first number that is divisible of 3
		for(int i = 1;i<=range;i++) {

			if(left > right) {
				return 0;
			}
			else if(left <= right and left%3 == 0) {
				break;
			}
			else{
				left++;
			}
		} 
		ll numbersTillLeft = left/3;

		for(int i = 1;i<=3;i++) {

			if(left > right) {
				return 0;
			}
			else if(left <= right and right%3 == 0){
				break;
			}
			else{
				right--;
			}
		}

		ll numbersTillRight = right/3;
		// adding one cary for the inclusion of left number...
		cout << (numbersTillRight-numbersTillLeft+1) <<"\n"; 
	}
	return 0;
}
