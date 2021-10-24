#include<iostream>
#include<vector>

using namespace std;

class DSU{
public:
	vector<int> rank,parent;
	void initializer(int n) {
		for(int i = 0;i<=n;i++) {
			rank.push_back(1);
			parent.push_back(i);
		}

	}
	int findParent(int x) {

		// base case
		if(x == parent[x]) {
			// x is a parent of itself...
			return x;
		}
		else{
		  return parent[x]  = findParent(parent[x]);
		}
	}
	void Union(int x,int y) {

		x = findParent(x);
		y = findParent(y);

		if(x != y) {

			if(rank[x] > rank[y]) {
				parent[y] = x;
				rank[x] += rank[y];
			}
			else{
				parent[x] = y;
				rank[y] += rank[x];
			}
		}
		return;
	}

};

void countIslands(int n,int m) {
	vector<vector<int>>ds(n,vector<int>(m,0));
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++ ) {
			cout << (i*m) + (j+1) <<" ";
		}
		cout <<'\n';
	}
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
	cout << "DSU " << "\n";
	DSU *ds = new DSU();
	countIslands(3,4);
	ds->initializer(4);
	ds->Union(1,2);
	ds->Union(3,2);
	ds->Union(4,3);
	cout << ds->findParent(1) <<" ";
}