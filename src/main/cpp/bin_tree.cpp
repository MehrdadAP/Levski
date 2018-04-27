#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
	Node *right,*left;
	char value;

	Node(char v){
		value = v;
		right = left = NULL;
	}
};

vector<char> arr;


Node* makeSubTree(int l, int r){
	if (l>r) return NULL;

	int mid= (l+r)/2;
	Node* root = new Node(arr[mid]);


	root->left = makeSubTree(l, mid-1);
	root->right = makeSubTree(mid+1, r);

	return root;
}


Node* makeBinTree(){
	return makeSubTree(0, arr.size()-1);
}


void inOrderTraverse(Node* cur){
	if (cur == NULL) return;

	inOrderTraverse(cur->left);
	cout << cur->value << " ";
	inOrderTraverse(cur->right);
}

void eulerTraverse(Node* root){
	if (root == NULL) return;

	cout << root->value << " ";
	if (root->left!=NULL){
		eulerTraverse(root->left);
		cout << root->value << " ";	
	}
	if (root->right!=NULL){
		eulerTraverse(root->right);
		cout << root->value << " ";	
	}
	
}

/*
Given a Binary Tree, print left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from left side.
*/

vector<bool> isSeen;
void printLeftView(Node* root, int l){
	if (root==NULL) return;
	if (!isSeen[l])
		cout << root->value << " ";
	isSeen[l]=true;

	printLeftView(root->left, l+1);
	printLeftView(root->right, l+1);
}


Node* manualTree(){
	Node* root = new Node('G');
	
	root->left = new Node('F');
	root->right = new Node('B');

	root->left->left = new Node('X');
	root->left->right = new Node('H');

	root->left->right->left = new Node('A');
	root->left->right->right = new Node('K');

	root->right->left = new Node('C');
	root->right->right = new Node('D');

	return root;
}

Node* manualTree2(){
	Node* root = new Node('A');
	
	root->left = new Node('B');
	root->right = new Node('X');

	root->left->left = new Node('C');
	root->left->right = new Node('D');

	root->left->right->left = new Node('E');
	
	return root;
}

Node* readFromInput(){
	int N;
	cin >> N;
	arr.resize(N);
	for (int i=0;i<N;i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	Node* root = makeBinTree();

	return root;
}




int main(){
	
	//Node* root = readFromInput();
	Node* root = manualTree2();
	//inOrderTraverse(root);
	//eulerTraverse(root);

	//leftView
	int N=6;
	isSeen.resize(N,false);
	printLeftView(root, 0);

	return 0;
}