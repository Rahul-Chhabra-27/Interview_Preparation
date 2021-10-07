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
// Total no. of comparisions are O(n*n).............
// Total no. of swaps are 0(n)....
int minElementIdx(vector<int>& nums,int i,int n) {
    
    int minIdx = i;
    while(i < n) {
        if(nums[minIdx] > nums[i]) {
            minIdx = i;
        }
        i++;
    }
    return minIdx;
}
void selectionSort(vector<int>& nums,int n) {

    for(int i = 0;i<n;i++) {
        int idx = minElementIdx(nums,i,n);
        swap(nums[i],nums[idx]);
    }
    return;
}
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    selectionSort(nums,nums.size());
    for(int i = 0;i<nums.size();i++) cout << nums[i] <<" ";
    cout <<"\n"; 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}