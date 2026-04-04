/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); 
        ListNode* slow = dummy; 
        ListNode* fast = head; 
        
        while (fast && n > 0) {
            fast = fast -> next; 
            n--; 
        } 
        if (fast == nullptr) return head->next; 

        // now move both pointers 
        while (fast) {
            slow = slow->next; 
            fast = fast->next; 
        }

        // slow pointer is one node previous to the node to be deleted 
        slow->next = slow->next->next; 
        return head; 
    }
};
