Problem statement
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Example:
Alt text

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9




  void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return;
    }
    
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
    
    swap(root -> left, root -> right);
    
    return;
}
    

