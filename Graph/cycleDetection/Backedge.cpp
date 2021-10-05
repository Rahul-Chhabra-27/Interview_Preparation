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

bool isCycle = false;
void isGraphConatinsCycle(vector<vector<int>>G,int src,int parent,int visited[]) {

    // 1 ->> visited && inside recStack, 2 -->> visited buto not inside recStack 
    // 0->> not visited... 
    visited[src] = 1;

    for(int adj : G[src]) {

        if(!visited[adj]) {
            isGraphConatinsCycle(G,adj,src,visited);
        }
        // case of backedge....
        else if(visited[adj] == 1 and adj != parent ) {
            isCycle = true;
            return;
        }
    }
    visited[src] = 2;
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
    
    int n,m;
    cin >> n >> m;
    vector<vector<int> >G(n);
    int *visited = new int[n]{0}; // creating inside heap
    while(m--) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    isGraphConatinsCycle(G,0,-1,visited);
    
    delete [] visited;
    cout << isCycle << "\n";
    return 0;
}