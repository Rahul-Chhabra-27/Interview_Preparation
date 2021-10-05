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

int saveWorld(vector<vector<int> >& G,int n,int src,int des) {

    // base case
    if(src == des) {
        return 0;
    }
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    visited[src] = true;
    while(!q.empty()) {
        int currTown = q.front();
        q.pop();

        for(int adj : G[currTown]) {
            if(!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
                dis[adj] = dis[currTown]+1;
            }
        }
    }
    return dis[des]-1;
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
    
    int n, m;
    cin >> n >> m;
    vector<vector<int> >G(n+1);
    while(m--) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int src,des;
    cin >> src >> des;
    cout << saveWorld(G,n,src,des);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}