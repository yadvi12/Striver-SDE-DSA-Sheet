// Link - https://leetcode.com/problems/reverse-nodes-in-k-group/
// Time Complexity - O(N)
// Space Complexity - O(N)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;
        int temp = 0;
        ListNode* tempNode = head;
        
        while(tempNode != NULL)
        {
            tempNode = tempNode->next;
            temp++;
        }
        if(temp < k)
        {
            return head;
        }
        
        while(count < k && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        } 

        
        if(next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
    
};
