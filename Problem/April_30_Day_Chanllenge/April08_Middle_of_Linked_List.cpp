/*
    Date: 4/8/2020
    Link List 
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    
    ListNode* middleNode(ListNode* head) {
        int num_list=0;
        int result=0;
        struct ListNode *ptr = head;
        
        while(ptr!=NULL){
            ptr = ptr->next;
            num_list+=1;
        }
        
        ptr = head;
        for(int i=0;i<num_list/2;i++){
            ptr = ptr->next;
        }



        

        return ptr;
    }
};



/*
    Wise sol: set two pointers which are fast pointer and slow pointer
    the fast pointer switch the node->next->next every time, 
    while the slow pointer switch the node->next every time.
    By doing so, we can avoid double search the linked List.
*/

// SAMPLE
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
    {   
        fast=fast->next->next;
        slow=slow->next;

    }
    return fast->next==nullptr? slow:slow->next;

        
        
    }
};