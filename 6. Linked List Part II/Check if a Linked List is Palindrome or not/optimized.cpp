// Link - https://leetcode.com/problems/palindrome-linked-list/
// Time Complexity - O(N)
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
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
      if(head == NULL || head->next == NULL)
      {
          return true;
      }
       
        ListNode* temp = slow->next;
        slow->next = reverse(temp);
        
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        
        while(head2 != NULL)
        {
            if(head1->val != head2->val)
            {
                temp = slow->next;
                slow->next = reverse(temp);
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        temp = slow->next;
        slow->next = reverse(temp);
        return true;
        
    }
};
