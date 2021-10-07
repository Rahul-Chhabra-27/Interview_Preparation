#include<bits/stdc++.h>


const int N = 1e5;
std::vector<int> G[N];
int visited[N], disc[N], low[N], count = 1;
std::set<int> ap;
std::set<std::pair<int,int>> bridges;

void dfs(int src,int par) {

    int child = 0;   
    disc[src] = low[src] = count++;
    visited[src] = 1;
    for(int adj : G[src]) {
        if(!visited[adj]) {
            dfs(adj,src);
            child++;
            low[src] = std::min(low[adj],low[src]);

            if(par != -1 and low[adj] >= disc[src]) {
                ap.insert(src);
            }

            if(low[adj] > disc[src]) {
                bridges.insert({src,adj});
            }
        }
        else if(par != adj and visited[adj] == 1) {
            // backedge.......
            low[src] = std::min(low[src],disc[adj]);
        }
    }
    if(child > 1 and par == -1) {
        ap.insert(src);
    }

    visited[src] = 2;
    return;
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
    file_i_o();
    int n,m;
    std::cin >> n >> m;
    while(m--) {
        int x,y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,-1);
    for(int el : ap) std::cout << el << " ";
    std::cout << "\n";
    for(auto adj : bridges) std::cout << adj.first <<" "<<adj.second <<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}