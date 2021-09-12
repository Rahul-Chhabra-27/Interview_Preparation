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
 
 // Dutch national flag algorithm
void sortColors(std::vector<ll>& nums,int n) {

   int low =0;
   int high = n-1;
   int mid = 0;
   while(low < n and nums[low] == 0) low++;
   while(high >= 0 and nums[high] == 2) high--;
   mid = low;

   while(mid <= high) {

       if(nums[mid] == 0) {
           std::swap(nums[low],nums[mid]);
           low++;
           mid++;
       }
       else if(nums[mid] == 2) {
           std::swap(nums[high],nums[mid]);
           high--;
       }
       else {
           mid++;
       }
   }
}
// second assumption.... working
void sortColors2(std::vector<ll>& nums,int n) {

    int low  = 0;
    int high = n-1;
    int mid = 0;
    while(low < n and nums[low] == 0) low++;
    while(high >= 0 and nums[high] == 2) high--;

    while(mid <= high) {

        if(nums[mid] == 0) {
            std::swap(nums[low],nums[mid]);
            low++;
        }
        else if(nums[mid] == 2) {
            std::swap(nums[high],nums[mid]);
            high--;
        }
        else{
            mid++;
        }
        if(mid <= low) mid = low;
    }
}
 
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    
    int n;
    std::cin >> n;
    std::vector<ll> nums(n);
    for(int i = 0;i<n;i++) {
        std::cin >> nums[i];
    }
    // sortColors(nums,n);
    sortColors2(nums,n);
    for(int i = 0;i<n;i++) {
        std::cout << nums[i] <<" ";
    }
    std::cout << nl;
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}