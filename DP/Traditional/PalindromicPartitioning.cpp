#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

bool isPalindrome(string str,int s,int e) {
	int i = s;
	int j = e;
	while(i <= j){
		if(str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}
void PP(string &str,int s,int n,vector<vector<string>>& ans,vector<string>& curr) {
	
	// base case
	if(s == n){
		ans.push_back(curr);
		return;
	}

	for(int k =s;k<n;k++) {
		if(isPalindrome(str,s,k)) {
			curr.push_back(str.substr(s,(k-s+1)));
			PP(str,k+1,n,ans,curr);
			curr.pop_back();
		}
	}
	return;
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

	string str;
	cin >> str;
	int n = str.size();
	vector<string> curr;
	vector<vector<string>>ans;
	PP(str,0,n,ans,curr);

	for(auto it : ans) {
		for(string st : it) {
			cout <<st << " ";
		}
		cout<<"\n";
	}
}