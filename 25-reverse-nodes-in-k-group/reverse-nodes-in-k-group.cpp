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
//reverse nodes in k group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        
        // 1. Check if at least k nodes exist
        while (cnt < k) { 
            if (temp == NULL) {
                return head; // Less than k nodes left, leave them as is
            }
            temp = temp->next; 
            cnt++;
        }
        
        // 2. Recursively call for the rest of the Linked List
        ListNode* prevNode = reverseKGroup(temp, k);
        
        // 3. Reverse the current group of k nodes
        temp = head; 
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }
        
        return prevNode;
    }
};
