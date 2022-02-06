// Link - https://leetcode.com/problems/copy-list-with-random-pointer/
// Time Complexity - O(N)
// Space Complexity - O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        //step1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        //step2: change the pointers
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        Node* originalNodeforward = NULL;
        Node* cloneNodeforward = NULL;
        
        while(originalNode != NULL)
        {
            originalNodeforward = originalNode->next;
            cloneNodeforward = cloneNode->next;
            originalNode->next = cloneNode;
            cloneNode->next = originalNodeforward;
            originalNode = originalNodeforward;
            cloneNode = cloneNodeforward;
        }
        
        //step3: copy the arbitrary pointers for clone Linked List
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL)
        {
            if(originalNode->random != NULL)
            {
                 cloneNode->random =originalNode->random->next;
            }
            else{
                cloneNode->random = NULL;
            }
                originalNode = originalNode->next->next;
                if(originalNode != NULL)
                {
                    cloneNode = cloneNode->next->next;
                }
                
        }
        
       
        //step4: revert the changes done in step2
        originalNode = head;
        cloneNode = cloneHead;
        originalNodeforward = NULL;
        cloneNodeforward = NULL;
        
        while(originalNode != NULL)
        {
            originalNodeforward = originalNode->next->next;
            originalNode->next = originalNodeforward;
            originalNode = originalNodeforward;
            
            if(originalNode != NULL)
            {
                cloneNodeforward = cloneNode->next->next;
                cloneNode->next = cloneNodeforward;
                cloneNode = cloneNodeforward;
            }
            else
            {
               cloneNode->next = NULL; 
            }
            
            
            
           
        }
        
        //step5: return the clone list
        
         return cloneHead;
    }
};
