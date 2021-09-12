#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll GCD(ll a , ll b) {
    return b == 0 ? a : GCD(b,a%b);
}

void isValid(vector<ll> nums,int n,int k) {

    ll gcd = 0;

    if(n == 1) {
        gcd = nums[0];
    }
    else {
        gcd = GCD(nums[0],nums[1]);
        for(int i = 2;i<n;i++) {
            gcd = GCD(gcd,nums[i]);
        }
    }
    ll max_prime = 0;
    for(int i = 2;i<=sqrt(gcd);i++) {
        max_prime = 0;
        while(gcd%i == 0){
            gcd = gcd/i;
            max_prime = max(max_prime,(ll)i);
        }
    }
    max_prime = max(max_prime,gcd);

    if(max_prime <= k) {
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" <<'\n';
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<ll> nums(n);
        for(int i = 0;i<n;i++) cin >> nums[i];
        isValid(nums,nums.size(),k);
    }
    return 0;
}
