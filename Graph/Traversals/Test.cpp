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

void Dfs(vector<vector<int> >G,int src,vector<bool>& visited) {

   cout << src <<" ";
   visited[src] = true;
   for(int adj : G[src]) {
       if(!visited[adj]) {
           Dfs(G,adj,visited);
       }
   }
}
void Bfs(vector<vector<int>>G,int src,int n) {

    vector<bool> visited(n+1,false);
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()) {
        int currVer = q.front();
        cout << currVer << " ";
        q.pop();
        for(int adj : G[currVer]) {
            if(!visited[adj]) {
              visited[adj] = true;
              q.push(adj);  
            }
        }
    }
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

    int n;
    int m;
    cin >> n >> m;
    vector<vector<int> >G(n+1);

    while(m--) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    // for(int i = 1;i<=n;i++) {
    //     if(!visited[i]) {
    //         Dfs(G,i,visited);
    //     }
    // }
    Bfs(G,1,n);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}