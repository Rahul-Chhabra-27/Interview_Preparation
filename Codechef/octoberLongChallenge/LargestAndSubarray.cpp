#include<bits/stdc++.h>
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
using namespace std;

ll largestSequence(ll n) {

    if(n == 1 || n == 2) {
        return 1;
    }
    int curr = 0;
    for(int i = 1;i<=32;i++) {

        if((ll)pow(2,i) <= n) {
            curr = i;
        }
        else{
            break;
        }
    }
    ll op1 = (ll) pow(2,curr)-(ll) pow(2,curr-1);
    ll op2 = (ll) n-pow(2,curr)+1;
    return max(op1,op2);
}
void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    // Write your code here....
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << largestSequence(n) <<" \n";
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}