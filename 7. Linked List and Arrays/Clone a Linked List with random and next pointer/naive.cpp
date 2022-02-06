// Link - https://leetcode.com/problems/copy-list-with-random-pointer/
// Time Complexity - O(N)
// Space Complexity - O(N) - created hashmap

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
        
        //step2: create an unordered map
        unordered_map<Node*, Node*> oldToNewNode;
        
        temp = head;
        Node* temp2 = cloneHead;
        while(temp != NULL)
        {
            oldToNewNode[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        //step3: arrange the random pointers
        temp = head;
        temp2 = cloneHead;
        while(temp != NULL)
        {
            temp2->random = oldToNewNode[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
};
