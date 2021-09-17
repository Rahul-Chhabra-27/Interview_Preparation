#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

ll minStudents(vector<ll>& S,vector<ll>& A,int n,int m,int k) {

	unordered_map<ll,int> map;

	for(int i = 0;i<m;i++) {
		map[A[i]]++;
	}
	ll count = 0;
	for(int i = 0;i<n;i++) {
		int currentFlat = S[i];
		if(map.count(currentFlat)) {
			++count;
			int freq = map[currentFlat];
			if(freq == 1) {
				map.erase(currentFlat);
			}
			else {
				map[currentFlat] = freq-1;
			}
		}
		else if(map.count(currentFlat+k)) {
			++count;
			int freq = map[currentFlat+k];
			if(freq == 1) {
				map.erase(currentFlat+k);
			}
			else {
				map[currentFlat+k] = freq-1;
			}
		}
		else if(map.count(currentFlat-k)) {
			count++;
			int freq = map[currentFlat-k];
			if(freq == 1) {
				map.erase(currentFlat-k);
			}
			else {
				map[currentFlat-k] = freq-1;
			}
		}
	}
	return count;
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

	int n,m,k;
	cin >> n >> m >> k;
	vector<ll> S(n);
	vector<ll> A(m);

	for(int i = 0;i<n;i++) cin >> S[i];
	for(int j = 0;j<m;j++) cin >> A[j];
	cout << minStudents(S,A,n,m,k) <<"\n";
}