class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // time and space complexity = O(max(l1.size() , l2.size()))
        // Initialize pointers for traversal
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        // Dummy head for result linked list
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        
        // Variable to keep track of carry
        int carry = 0;
        
        // Traverse both input linked lists until at least one is exhausted
        while(temp1 != NULL || temp2 != NULL)
        {
            // Initialize sum with carry
            int sum = carry;
            
            // Add the current values of the nodes if they exist
            if(temp1)
            {
                sum += temp1 -> val;
            }
            if(temp2)
            {
                sum += temp2 -> val;
            }
            
            // Create a new node with the digit sum modulo 10
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10; // Update carry
            
            // Append the new node to the result linked list
            curr -> next = newNode;
            curr = curr -> next; // Move the current pointer
            
            // Move to the next nodes in both linked lists if they exist
            if(temp1){
                temp1 = temp1 -> next;
            }
            if(temp2){
                temp2 = temp2 -> next;
            }
        }
        
        // If there's still a carry, append it as a new node
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr -> next = newNode;
        }
        
        // Return the result linked list starting from the node after the dummy head
        return dummyHead -> next;
    }
};
