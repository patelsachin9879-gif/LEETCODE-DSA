//LL cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;

        // Phase 1: Determine if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        // If no cycle is found, return NULL
        if (!isCycle) {
            return NULL;
        }

        // Phase 2: Find the entry point of the cycle
        slow = head; 
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // The meeting point is the start of the cycle
    }
};