#include<iostream>
#include <bits/stdc++.h>

#define ll long long int

ll gcd(ll a,ll b) {

    // base case
    if(b == 0){
        return a;
    }
    // recursive intution
    return gcd(b,a%b);
}

ll lcm(ll a,ll b) {
    
    if(a == 0 || b == 0) {
        return 0;
    }
    return (a*b)/gcd(a,b);
}
int main(int argc, char const *argv[])
{
    int t;
    std::cin >> t;
    
    while(t--) {
        ll a ,b;
        std::cin >>a>>b;
        std::cout << gcd(a,b) << " "<< lcm(a,b) <<'\n';
    }
    return 0;
}
