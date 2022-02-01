// Link - https://leetcode.com/problems/middle-of-the-linked-list/
// Time Complexity - O(N) + O(N/2) ~ O(N)
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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            length++;
            temp = temp->next; 
        }
        
        int count = 0;
        while(count < length/2)
        {
            head = head->next;
            count++;
        }
        return head;
    }
};
