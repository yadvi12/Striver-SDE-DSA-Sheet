// Link - https://leetcode.com/problems/add-two-numbers/
// Time Complexity - O(max(m,n))
// Space Complexity - O(max(m,n))

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
        ListNode* prev = NULL;
        ListNode* curr = head;
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
void insertAtTail(ListNode *&tail, int data)
{
    ListNode *tempNode = new ListNode(data);

    tail->next = tempNode;
    tail = tempNode;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3 = new ListNode(NULL);
        ListNode* head = l3;
        ListNode* tail = l3;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int value1 = 0;
            if(l1 != NULL)
            {
                value1 = l1->val;
            }
            int value2 = 0;
            if(l2 != NULL)
            {
                value2 = l2->val;
            }
            int digit = (value1 + value2 + carry)%10;
            
            carry = (value1 + value2 + carry)/10;
            insertAtTail(tail, digit);
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                 l2 = l2->next;
            }
           
        }
        
        return l3->next;
    }
};
