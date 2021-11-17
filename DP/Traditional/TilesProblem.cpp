#include<iostream>
#include<vector>

using namespace std;

#define ll long long int
#define mod 1000000007


vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
	int n = A.size();
	vector<vector<ll>> ans(n,vector<ll>(n,0));
	for(int i =0;i<n;i++) {
		for(int j =0;j<n;j++) {
			for(int k = 0;k<n;k++) {
				ans[i][j] = (ans[i][j]%mod + ((A[i][k]%mod)*(B[k][j]%mod))%mod)%mod;
			}
		}
	}
	return ans;
}
vector<vector<ll>> matrixExponentiation(vector<vector<ll>>&A,ll k) {

	// base case
	if(k == 1){
		return A;
	}
	vector<vector<ll>> ans = matrixExponentiation(A,k/2);

	if(k&1) {
		return multiply(multiply(ans,ans),A);
	}
	else{
		return multiply(ans,ans);
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

	ll n;
	cin >> n;
	vector<vector<ll>>A = {{1,1},{1,0}};
	vector<vector<ll>> ans = matrixExponentiation(A,n);
	cout << ans[0][0] << "\n";
}	