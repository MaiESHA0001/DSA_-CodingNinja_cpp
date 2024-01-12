Problem statement
For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.

Note :
1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
2. Don't create a new linked list.
3.  Just change the data, instead rearrange the provided list.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40














  /****************************************************************
 
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

Node *evenAfterOdd(Node *head)
{
	//write your code here
	  if(!head or !(head -> next)) {
        return head;
    }
    
    Node *curr = head;
    Node *odd_Head = NULL;
    Node *odd_Tail = NULL;
    Node *even_Head = NULL;
    Node *even_Tail = NULL;
    
    while(curr) {
        if(curr -> data & 1) {
            if(odd_Head == NULL) {
                odd_Head = curr;
                odd_Tail = curr;
            } else {
                odd_Tail -> next = curr;
                odd_Tail = curr;
            }
        } else {
            if(even_Head == NULL) {
                even_Head = curr;
                even_Tail = curr;
            } else {
                even_Tail -> next = curr;
                even_Tail = curr;
            }
        }
        curr = curr -> next;
    }
    
    if(odd_Head == NULL) {
        return even_Head;
    } else {
        if(even_Head == NULL) {
            return odd_Head;
        } else {
            odd_Tail -> next = even_Head;
            even_Tail -> next = NULL;
            return odd_Head;
        }
    }

}
