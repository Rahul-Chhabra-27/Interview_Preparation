#include<bits/stdc++.h>

using namespace std;

#define ll   long long int
#define vii  vector<vector<long long int>>
#define mod  1000000007

vii multiply(vii a,vii b) {

	int n = a.size();
	vii ans(n,vector<ll>(n));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			for(int k = 0;k<n;k++) {
				ans[i][j] = (ans[i][j]%mod + (a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}
	return ans;
}
vii power_(vii &mat,ll exp) {
	if(exp == 1){
		return mat;
	}
	vii res = power_(mat,exp/2);

	if(exp&1) {
		return multiply(multiply(res,res),mat);
	}
	else{
		return multiply(res,res);
	}
}
ll  walk(vii &arr,ll k,int n) {
	vii res = power_(arr,k);
	ll ans = 0;
	for(int i =0 ;i<n;i++) {
		for(int j = 0;j<n;j++) {
			ans = (ans%mod + res[i][j]%mod)%mod;
		}
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

	int n;
	cin >> n;
	ll k;
	cin >> k;
	vii arr(n,vector<ll>(n));
	for(int i = 0;i<n;i++) {
		for(int j =0;j<n;j++) {
			cin >> arr[i][j];
		}
	}
	cout << walk(arr,k,n) <<"\n";
}