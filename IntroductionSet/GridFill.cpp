#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

void fillGrid(vector<vector<int> >&G,int n) {

	if(n&1) {
		int idx = 0;
		while(idx < n) {
			G[idx][idx] = 1;
			idx++;
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j =0;j<n;j++) {
			cout << G[i][j] <<" ";
		}
		cout <<"\n";
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
		vector<vector<int> >G(n,vector<int>(n,-1));
		fillGrid(G,n);
	}

}