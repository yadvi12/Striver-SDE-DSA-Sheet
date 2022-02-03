// Link - https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* solve(ListNode* list1, ListNode* list2)
    {
    if(list1->next == NULL)
    {
        list1->next = list2;
        return list1;
    }
    ListNode* prev1 = list1;
    ListNode* curr1 = list1->next;
    ListNode* prev2 = list2;
    ListNode* curr2 = prev2->next;
    
    while(curr1 != NULL && prev2 != NULL)
    {
        if(prev2->val >= prev1->val && prev2->val <= curr1->val)
        {
            prev1->next = prev2;
            curr2 = prev2->next;
            prev2->next = curr1;
            
            prev1 = prev2;
            prev2 = curr2;
            
        }
        else
        {
            prev1 = curr1;
            curr1 = curr1->next;
            
            if(curr1 == NULL)
            {
                prev1->next = prev2;
                return list1;
            }
        }
    }
    return list1;
}
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
            return list2;
        }
        if(list2 == NULL)
        {
            return list1;
        }
        if(list1->val <= list2->val)
        {
            return solve(list1, list2);
        }
        else{
            return solve(list2, list1);
        }
    }
};
