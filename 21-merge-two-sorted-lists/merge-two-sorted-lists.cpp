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
//merge two shorted list
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // Base Case: If either list is empty, return the other list
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        
        // Case 1: If head1's value is smaller or equal
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } 
        // Case 2: If head2's value is smaller
        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};