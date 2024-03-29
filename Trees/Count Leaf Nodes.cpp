Problem statement
Given a generic tree, count and return the number of leaf nodes present in the given tree.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4








  #include<vector>

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return 0;
    }
    
    //base case
    if(root -> children.size() == 0) {
        return 1;
    }
    
    int count = 0 ;
    for(int i = 0; i < root -> children.size() ; i++) {
        count += getLeafNodeCount(root -> children[i]);
    }
    
    return count;
}
