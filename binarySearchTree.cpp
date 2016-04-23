#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node *left;
	node * right;
};

node* insert(node *root, int value) {
	// check if tree is empty
	node *temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	if(root==NULL)
		root = temp;
	else {
		if(root->data > value)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
	}
	return root;
}

int preorder(node * root) {
	if(root!=NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}

int inorder(node * root) {
	if(root!=NULL){		
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

int postorder(node * root) {
	if(root!=NULL){		
		postorder(root->left);		
		postorder(root->right);
		printf("%d ", root->data);
	}	
}

int getNodesCount(node *root) {	
	if (root==NULL)	
		return 0;
	return getNodesCount(root->left) + 1 + getNodesCount(root->right);
}

int getHeight(node *root) {
	if(root==NULL)
		return 0;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

int checkIfTreeIsBalanced(node *root) {
	if(root == NULL)
		return 1;	
	checkIfTreeIsBalanced(root->left);
	checkIfTreeIsBalanced(root->right);
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	return abs(leftHeight-rightHeight) < 2; 
}

int checkIfBST(node *root,int min,int max) {
	if(root==NULL)
		return 1;
	return root->data > min && root->data < max && checkIfBST(root->left,min,root->data) && checkIfBST(root->right,root->data,max);
}

int main(int argc, char const *argv[])
{
	node *root=NULL;
	int n,data;
	printf("Please enter number of nodes : ");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		root = insert(root,data);
	}	
	printf("Preorder Traversal\n");
	preorder(root);
	printf("\n");
	printf("Inorder Traversal\n");	
	inorder(root);
	printf("\n");
	printf("Postorder Traversal\n");	
	postorder(root);
	printf("\n");
	printf("Get number of nodes in the tree\n");
	printf("%d\n", getNodesCount(root));
	printf("Get height of the tree\n");
	printf("%d\n", getHeight(root));	
	printf("Check if tree is balanced : ");
	printf("%s\n", (checkIfTreeIsBalanced(root)==1?"Yes": "NO"));
	return 0;
}