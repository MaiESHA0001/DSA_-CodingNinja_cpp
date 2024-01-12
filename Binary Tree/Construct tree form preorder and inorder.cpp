/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/











/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	    int rootData = preorder[0]; 
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);
    
    if(preLength == 1) {     
        return root;
    } else if(preLength == 0) { 
        return NULL;
      }
    
    int rootIndex = 0;
    
    while(inorder[rootIndex] != rootData){
        rootIndex++;
    }
    
    int leftLength = rootIndex;
    int rightLength = inLength - rootIndex  - 1;
    
    BinaryTreeNode<int> *left = buildTree(preorder + 1, leftLength, inorder, leftLength);
    BinaryTreeNode<int> *right = buildTree(preorder + 1 + leftLength, rightLength, inorder + 1 + leftLength, rightLength);
    
    root -> left = left;
    root -> right = right;
    
    return root;
}
