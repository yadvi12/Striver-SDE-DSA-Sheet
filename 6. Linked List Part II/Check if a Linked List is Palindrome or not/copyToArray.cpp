// Link - https://leetcode.com/problems/palindrome-linked-list/
// Time Complexity - O(N) + O(N) ~ O(N)
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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        int start = 0;
        int end = n-1;
        bool value = true;
        while(start <= end)
        {
            if(ans[start] == ans[end])
            {
                start++;
                end--;
            }
            else{
                value = false;
                break;
            }
        }
        return value;
    }
};

