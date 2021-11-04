#include<bits/stdc++.h>

using namespace std;

// Time complexity is O(max(m,n))........
pair<int,int> searchInMatrix(vector<vector<int>>&matrix,int target) {

	int n = matrix.size();
	int m = matrix[0].size();

	int row = 0;
	int col = m-1;

	while(row < n && col >= 0) {

		if(matrix[row][col] == target){
			return {row,col};
		}
		else if(matrix[row][col] > target) {
			col--;
		}
		else {
			row++;
		}
	}
	return {-1,-1};
}
int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt","r",stdin);

		// for writting output to output.txt
		freopen("output.txt","w",stdout);
		// --------------------------output-------------------------------//
	#endif

	int n,m,target;
	cin >> n >> m >> target;
	vector<vector<int>> matrix(n,vector<int>(m));

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			int x;
			cin >> x;
			matrix[i][j] = x;
		}
	}
	pair<int,int> ans = searchInMatrix(matrix,target);
	cout << ans.first << " "<< ans.second << "\n";
}