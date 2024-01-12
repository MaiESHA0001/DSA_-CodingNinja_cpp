Problem statement
You have been given a head to a doubly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Note:
There is no requirement for input or output handling. Your task is to implement a function that returns whether the given doubly linked list is a palindrome or not. The nodes in the doubly linked list are connected to its previous nodes using a 'prev' pointer in addition to the usual next pointer.
Detailed explanation ( Input/output format, Notes, Images )
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the doubly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.














  /****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
				this->prev = NULL;
	        }
        };

*****************************************************************/
bool palindromeDLL(Node* head){
       if (head == nullptr || head->next == nullptr) {
        // An empty list or a list with one node is always a palindrome
        return true;
    }

    // Traverse to the end of the list to find the tail
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            // If data at current head and tail nodes don't match, it's not a palindrome
            return false;
        }

        // Move to the next nodes
        head = head->next;
        tail = tail->prev;
    }

    // If the loop completes without returning, the list is a palindrome
    return true;

}

