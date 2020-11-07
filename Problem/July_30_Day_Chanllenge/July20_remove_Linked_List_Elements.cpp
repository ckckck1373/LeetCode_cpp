/*
    Date: 2020/7/20
    Owner: Chun-Yeh, Lin
    Note: 
*/

// version1: Runtime: 28ms(60.73%)/ Memory Usage:13.6MB(49.51%)

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
    ListNode* removeElements(ListNode* head, int val) {

        struct ListNode* temp = NULL;
        
    
        while(head && head->val==val){
            if(head->next){
                head = head->next;
            }else{
                head = NULL;
            }
            
        }
        
        temp = head;
        while(temp && temp->next){
            if(temp->next->val==val){
                if(temp->next->next){
                    temp->next = temp->next->next;
                }else{
                    temp->next = NULL;
                }
                
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};