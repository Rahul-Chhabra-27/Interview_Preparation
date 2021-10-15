#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ff first
#define ss second

class TreeNode {
	public:
		int data;
		TreeNode* left;
		TreeNode* right;

	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* build() {
	int d;
	cin >> d;
	if(d == -1) return NULL;

	TreeNode *root = new TreeNode(d);

	root->left = build();
	root->right = build();
	return root;

}
void inorder(TreeNode* root) {

	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);

}
void preorder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}
void postorder(TreeNode* root) {
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";

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
	TreeNode* root = build();
	inorder(root);
	cout << "\n";
	preorder(root);
	cout <<"\n";
	postorder(root);
	cout <<"\n";
	cout << (int)log2(100) <<" ";
}