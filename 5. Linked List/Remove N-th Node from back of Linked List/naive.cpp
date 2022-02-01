// Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time Complexity - O(N) + O(N-count) ~ O(N)
// Space Complexity - O(1)

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
        int length = 0;
        ListNode* temp = head;
        if(head->next == NULL)
        {
            return NULL;
        }
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        if(n == length)
        {
            return head->next;
        }
        int count = 1;
        ListNode* start = head;
        ListNode* forward = start->next;
        while(count < length-n)
        {
            start = start->next;
            forward = start->next;
            count++;
        }

        
        start->next = forward->next;
        forward->next = NULL;
        
        return head;
    }
};
