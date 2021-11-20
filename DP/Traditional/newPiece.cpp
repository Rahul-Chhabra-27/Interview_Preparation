#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int minSteps(int a,int b,int p,int q) {

	if(a == p and b == q){
		return 0;
	}
	int x = a+b;
	int y = p+q;
	int z = abs(x-y);

	if(z&1) {
		return 1;
	}
	else{
		return 2;
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
		int a,b,p,q;
		cin >>a>>b>>p>>q;
		cout <<minSteps(a,b,p,q)<<"\n";
	}
}