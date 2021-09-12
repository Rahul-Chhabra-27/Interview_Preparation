#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int dx[] = {-1,-1,-1,1,1,1,0,0};
int dy[] = {-1,1,0,-1,0,1,-1,1};

ll minHours(vector<vector<int>>& grid,int n,int m,ll &maxVal) {

    // queue
    queue<pair<int,int>> q;
    ll countHours = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(grid[i][j] == maxVal) {
                q.push({i,j});
            }
        }
    }
    if(q.size() == (ll)m*n) {
        return 0;
    }
    q.push({-1,-1});
    while(q.size() > 1) {
        auto currPosition = q.front();
        q.pop();
        int x = currPosition.first;
        int y = currPosition.second;
        if(x == -1 and y == -1) {
            countHours++;
            q.push({-1,-1});
        }
        else{
            for(int i = 0;i<8;i++) {
                int xx = x+dx[i];
                int yy = y+dy[i];

                if(xx < n and yy < m  and xx >= 0 and yy >= 0 and (ll)grid[xx][yy] != maxVal) {
                    grid[xx][yy] = maxVal;
                    q.push({xx,yy});
                }
            }
        }
    }
    return countHours;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        ll maxValue = 0;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                cin >> grid[i][j];
                maxValue = max(maxValue,(ll)grid[i][j]);
            }
        }
        cout << minHours(grid,n,m,maxValue) <<"\n";
    }
}