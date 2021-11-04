#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	int ans = 0;
	string str = "9999999999";
	int n = str.size();
	for(int i = 0;i<n;i++) {
		ans += (str[i]-'0');
	}
	cout << ans  << "\n";
}