#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int maxLen(string s) {
	stack<int>st;
	int maxLength = 0;
	int n = s.size();
	for(int i=0;i<n;i++) {

		if(s[i] == '(') {
			st.push(1);
		}
		else if(s[i] == ')' and !st.empty()) {
			st.pop();
			maxLength += 2;
		}
	}
	return maxLength;
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

	string s;
	cin >>s;
	cout << maxLen(s) <<"\n";
}