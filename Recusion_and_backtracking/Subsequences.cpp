#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

void printSubsequences(string str,string osf,int i,int n) {

	// base case
	if(i == n) {
		cout << osf <<"\n";
		return;
	}

	// recursive intution
	printSubsequences(str,osf+str[i],i+1,n);
	printSubsequences(str,osf,i+1,n);

	return;
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
	string str = "abc";
	printSubsequences(str,"",0,str.size());
}