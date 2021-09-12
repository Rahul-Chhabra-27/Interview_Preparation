#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1,1,0,0}; // up down left right
int dy[] = {0,0,-1,1};

int minTime(vector<vector<int>>&G,int n,int m) {

    queue<pair<int,int>>rotten;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            // check for rooten oranges
            if(G[i][j] == 2) {
                rotten.push({i,j});
                G[i][j] = 0;
            }
        }
    }
    rotten.push({-1,-1});
    int count = 0;
    while(rotten.size() > 1) {
        auto currentPos = rotten.front();
        rotten.pop();
        int x = currentPos.first;
        int y = currentPos.second;

        if(x == -1 and y == -1) {
            count++;
            rotten.push({-1,-1});
        }
        else {
            for(int i = 0;i<4;i++) {
                int xx = x+dx[i];
                int yy = y+dy[i];

                // found a valid fresh orange
                if(xx < n and yy < m and xx >= 0 and yy >= 0 and G[xx][yy] == 1) {
                    G[xx][yy] = 0;;
                    rotten.push({xx,yy});  
                }
            }
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j =0;j<m;j++) {
            if(G[i][j]){
                return -1;
            }
        }
    }
    return count;
}
int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<int>>G(n,vector<int>(m));

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin >> G[i][j];
        }
    }
    cout << minTime(G,n,m) <<"\n";
}