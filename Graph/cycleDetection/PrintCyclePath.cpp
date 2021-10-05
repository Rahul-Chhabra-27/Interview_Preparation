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

void printBackedges(vector<int>G[],int src,int par,int visited[]) {
    visited[src] = 1;

    for(int adj : G[src]) {

        if(!visited[adj]) {
            printBackedges(G,adj,src,visited);
        }
        else if(adj != par and visited[adj] == 1) {
            cout <<"Backedges -- >> " <<  src << " " << adj<<"\n";
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
    
    int n,m;
    cin >> n >> m;
    vector<int>G[n]; // Array of vectors.......
    int *visited = new int[n]{0};
    while(m--) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0;i<n;i++) {
        if(!visited[i]) {
            printBackedges(G,i,-1,visited);
        }
    }
    return 0;
}