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
		int n;
		cin >> n;

		ll sumTillN = (n*(n+1))/2;
		ll half = sumTillN/2;
		cout << sumTillN <<"\n";
		int start = 1;
		int end = n;

		vector<int> A;
		vector<int>B;
		ll sumA = 0;
		ll sumB = 0;
		bool flag = true;
		while(start < end) {
			if(flag) {
				A.push_back(start);
				A.push_back(end);
				sumA += (start+end);
			}
			else{
				B.push_back(start);
				B.push_back(end);
				sumB += (start+end);
			}
			start++;
			end--;
		}

		if(sumA == half and sumB == half){
			sort(A.begin(),A.end());
			sort(B.begin(),B.end());
			cout << "YES"<<'\n';
			for(int i : A) cout << i <<" ";
			cout <<"\n";
		    for(int i : B) cout << i <<'\n';
		    cout <<"\n";
		}
		else{
			cout <<"NO" <<'\n';
		}
		
	}
}