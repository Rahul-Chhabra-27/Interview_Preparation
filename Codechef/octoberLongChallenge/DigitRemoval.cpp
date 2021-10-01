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

void digitRemoval(ll n, ll d ) {

    // base case
    if(n == d){
        cout << 1 << "\n";
        return;
    }
    vector<int> digits;
    int lastPosition = -1;
    ll copy = n;
    while(copy > 0) {
        int num = copy%10;
        copy /= 10;
        digits.push_back(num);
    }
    reverse(all(digits));
    for(int i = 0;i<digits.size();i++) {
        if(digits[i] == d) {
            lastPosition = i;
            break;
        }
    }
    // // check if digit is present or not....
    if(lastPosition != -1) {
        vector<int> ans;
        int len = digits.size();
        if(d != 0) {
            int carry = 0;
            for(int i = len-1;i>lastPosition;i--) {
                int sum = digits[i] + carry;
                if(sum != 10) {
                    ans.push_back(10-sum);
                }
                carry= 1;
            }
        }
        else {
            int carry = 0;
            for(int i = len-1;i>=lastPosition;i--) {
                if(digits[i] == 0 and carry == 1 and i != lastPosition) {
                    ans.push_back(0);
                    carry = 0;
                }
                else if(digits[i] == 0 and carry == 0) {
                    ans.push_back(1);
                }
                else if(digits[i] == 1 and carry == 0){
                    ans.push_back(0);
                }

                else if(digits[i] != 0) {
                    int sum = digits[i] + carry;
                    ans.push_back(11-sum);
                    carry = 1;
                }
            }
        }
        reverse(all(ans));
        for(int i : ans) cout << i;
        cout <<'\n';
    }
    else{
        cout << 0 << "\n";
    }
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
        ll d;
        cin >> n >> d;
        digitRemoval(n ,d);
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}