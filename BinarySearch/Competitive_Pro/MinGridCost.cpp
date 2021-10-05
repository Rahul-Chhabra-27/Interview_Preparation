#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	ll t;
	cin >> t;
	while(t--) {

		ll n,m,x,y;
		cin >> n >> m >> x >> y;
		ll finalCalculation = 0;
		ll minValue = min(n,m);
		if(n == 1){
			cout << (m-1)*x <<"\n";
		}

		else if(m == 1){
			cout <<(n-1)*x <<"\n";
		}

		else{

			ll firstValue = (2*(minValue-1)*x);
			ll secondValue = (minValue-1)*y;

			if(firstValue >= secondValue) {
				finalCalculation = secondValue;
			}
			else{
				finalCalculation = firstValue;
			}
			 // when grid having square shape
			if(n == m){
				cout << finalCalculation <<"\n";
			}

			else if(x < y){
				finalCalculation += (n-minValue + m-minValue)*x;
			}
			else {
				
				ll remaining = max(n-minValue,m-minValue);

				if(remaining&1) {
					finalCalculation += (remaining-1)*y + x;
				}
				else{
					finalCalculation += remaining*y;
				}
			}
			cout << finalCalculation <<'\n';
		}
	}
}