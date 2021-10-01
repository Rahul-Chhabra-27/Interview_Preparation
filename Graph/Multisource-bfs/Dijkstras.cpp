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

// Dijkstra's Algorithm for single source shortest path.......
vector<int> dijkstras_Algo(vector<vector<pair<int,int>>>G,int src,int n) {

    set<pair<int,int>>set;
    vector<int> dis(n+1,INT_MAX);
    set.insert({0,src});
    dis[src] = 0;
    while(!set.empty()) {
        auto curr = *set.begin();
        set.erase(curr);
        int currVer = curr.second;
        int currWeight = curr.first; 
        for(auto adj : G[currVer]) {
            // performing relax operation on all the adjacent of currVer... 
            if(dis[adj.second] > dis[currVer] + adj.first) {
                set.erase({dis[adj.second],adj.second});
                dis[adj.second] = dis[currVer] + adj.first;
                set.insert({dis[adj.second],adj.second});
            }
        }
    }
    return dis;
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
    // file_i_o();
    // Write your code here....

    int n; // no. of vertices...
    int m; // no. of edges....
    cin >> n >> m;
    vector<vector<pair<int, int>> >G(n+1);

    // graph construction...
    while(m--) {
        int source,destination,weight;
        cin >> source >> destination >> weight;
        G[source].push_back({weight,destination});
        G[destination].push_back({weight,source});
    }
    vector<int> ans = dijkstras_Algo(G,1,n);
    for(int i = 1;i<=n;i++){
        cout << "Distance of " << i << " from vertex 1 is " << ans[i] <<"\n";  
    } 
    cout <<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}