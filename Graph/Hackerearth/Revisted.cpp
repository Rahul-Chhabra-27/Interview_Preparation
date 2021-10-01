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

void revisited(vector<vector<pair<int,int>> >G,int n,int k) {
    
    // distance vector
    vector<vector<int>>dis(n+1,vector<int>(k+1,INT_MAX));
    set<pair<int,pair<int,int>> > set; // dis , ver , offers....
    int src = 1;
    set.insert({0,{src,0}});
    dis[src][0] = 0;
    while(!set.empty()) {

        auto currVer = *set.begin();
        set.erase(currVer);
        int offers = currVer.second.second;
        int ver = currVer.second.first;

        for(auto adj : G[ver]) {
            int adjVer = adj.second;
            int adjWeight = adj.first;
            if(offers < k and dis[adjVer][offers+1] > dis[ver][offers]) {
                set.erase({dis[adjVer][offers+1],{adjVer,offers+1}});
                dis[adjVer][offers+1] = dis[ver][offers] + 0;
                set.insert({dis[adjVer][offers+1],{adjVer,offers+1}});
            }
            if(dis[adjVer][offers] > dis[ver][offers] + adjWeight) {
                set.erase({dis[adjVer][offers],{adjVer,offers}});
                dis[adjVer][offers] = dis[ver][offers] + adjWeight;
                set.insert({dis[adjVer][offers],{adjVer,offers}});
            }
        }
    }
    for(int i = 1;i<=n;i++) {
        int maxE = INT_MAX;
        for(int j = 0;j<=k;j++) {
            maxE = min(maxE,dis[i][j]);
        }
        cout << maxE << " ";
    }
    cout <<"\n";
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

    int n,m;  // n ->> no. of vertices m ->> no. of edegs..
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<vector<pair<int,int>> >G(n+1);
    while(m--) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    revisited(G,n,k);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}