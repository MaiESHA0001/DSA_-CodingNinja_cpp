Problem statement
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :

Alt txt

Image-II :

Alt txt

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Explanation of Sample Output 1 :
The data in the node with index 3 is 2 which has been removed.
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
4 5 2 6 1 9
Constraints :
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Expected Complexity :
Time Complexity  : O(N)
Space Complexity  : O(1)
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)









Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	 if(head==NULL){
		     return head;
	 }
            
        if(pos==0){
			   return head->next;
		}
       Node*curr=head;
	   int currPos=0;
	   while(curr!=NULL&&currPos< pos-1)
	   {
		   ++currPos;
		   curr=curr->next;
	   }
           if (curr == NULL || curr->next == NULL) {
                   return head;
           }
           curr->next = curr->next->next;
           return head;
}
