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

ll cheapestFllght(vector<vector<pair<int,int>>>&G,int n,int k,int src,int des) {

    set<pair<int,pair<int,int>>>set;
    vector<vector<int>>dp(n,vector<int>(k+2,INT_MAX));
    for(int i = 0;i<dp[0].size();i++) {
        dp[src][i] = 0;
    }
    set.insert({0,{src,0}});
    while(!set.empty()) {
        auto currPair = *set.begin();
        set.erase(currPair);
        int currVer = currPair.second.first;
        int currW = currPair.first;
        int currK = currPair.second.second;
        // relax operation to all the adjacents....
        for(auto adj : G[currVer]) {

            int adjVer = adj.second;
            int edgeW = adj.first;

            if(currK < k+1 and dp[adjVer][currK+1] > dp[currVer][currK] + edgeW) {
                set.erase({dp[adjVer][currK+1],{adjVer,currK+1}});
                dp[adjVer][currK+1] = dp[currVer][currK]+ edgeW;
                set.insert({dp[adjVer][currK+1],{adjVer,currK+1}});
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0;i<k+2;i++) {
       ans = min(dp[des][i],ans);
    }
    return ans;
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
    
    int n,m,k,src,des;
    cin >> n >> m >> k >> src >> des;
    vector< vector<pair<int,int> > >G(n);
    while(m--) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({w,v});
    }
    cout << cheapestFllght(G,n,k,src,des) <<"\n";
    return 0;
}