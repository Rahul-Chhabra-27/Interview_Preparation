#include<iostream>
#include<cstring>

using namespace std;

#define ll long long int
#define ff first
#define ss second

const int N = 3005;
int primes[N];
// TC :- O(NloglogN) ->> 1000*3*2 = 6000...

int countAlmostPrime(int n) {

	for(int i = 2;i<=n;i++) {
		if(!primes[i]) {
			for(int j = i;j<=n;j+=i) {
				primes[j]++;
			}
		}
	}
	int count =0;
	for(int i = 1;i<=n;i++) {
		if(primes[i] == 2){
			count++;
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

	int n;
	cin >> n;
	memset(primes,0,sizeof(primes));
	cout << countAlmostPrime(n)<<"\n";
}