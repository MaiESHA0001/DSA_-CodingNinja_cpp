Problem statement
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.

Return null if tree is empty.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50






  #include<climits>
#include<vector>

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    //corner case
    if(root == NULL){
        return root;
    }
    
    TreeNode<int> *maximum = root;
    
    for(int i = 0; i < root -> children.size() ;i++) {
        TreeNode<int> *temp = maxDataNode(root -> children[i]);
        if(temp -> data > maximum -> data) {
            maximum = temp;
        }	
    }
    return maximum;
}
