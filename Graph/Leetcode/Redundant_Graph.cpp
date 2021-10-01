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
ll find(int i,vector<ll> &parent, vector<ll> &rank) {

    if(parent[i] == i){
        return i;
    }
    else {
        return parent[i] = find(parent[i],parent,rank);
    }
} 
void Union(int x,int y,vector<ll> &parent,vector<ll> &rank) {

    x = find(x,parent,rank);
    y = find(y,parent,rank);

    if(x != y) {

        if(rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
}
vector<int> Rgraph(vector<vector<int> >G,int n,vector<ll>& parent,vector<ll>&rank) {

    vector<int> ans;

    for(int i = 0;i<n;i++) {
        
        int u = G[i][0];
        int v = G[i][1];

        if(find(u,parent,rank) == find(v,parent,rank)) {
            ans.push_back(u);
            ans.push_back(v);
        }
        else {
            Union(u,v,parent,rank);
        }
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
    clock_t begin = clock();
    // Write your code here....

    int n;
    cin >> n;
    vector<vector<int> >G(n);
    vector<ll> parent(n+1);
    vector<ll> rank(n+1);
    for(int i = 0;i<=n;i++) {
        parent[i] = i;
    }
    for(int i = 0;i<n;i++) {
        int u,v;
        cin >> u >> v;
        G[i] = vector<int>{u,v};
    }
    vector<int> ans = Rgraph(G,n,parent,rank);
    cout << ans[0] << " "<<ans[1] <<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}