#include<iostream>

using namespace std;

#define ll long long int


// T(n,k) = (T(n,k/2) + O(1)) ->> O(logn)...
ll powerRecursively(ll a,ll k) {

	// base case
	if(k == 0) return 1;

	// now let's calculate the value for a**(k/2).
	ll ans = powerRecursively(a,k/2);

	// now check if the value of k is odd, if it is then,
	if(k&1) {
		// condition for odd.
		return ans*ans*a;
	}
	else{
		//condition for even 
		return ans*ans;
	}
}
// T(n) = O(logn).
ll powerIteratively(ll a, ll k) {

	ll ans = 1;

	while(k > 0) {

		// if the right most bit is set
		if(k&1) ans *= a;

		a *= a;
		k >>= 1;
	}
	return ans;
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

	ll a;
	ll k;
	cin >> a >> k;
	cout << powerRecursively(a,k)<<"\n";
	cout << powerIteratively(a,k) <<"\n";
}