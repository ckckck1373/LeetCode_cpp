/*
    Date: 2020/7/10
    Owner: Chun-Yeh, Lin
    Note: Double Linked List
          Linked List head node
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node* result_h = NULL; // head node
        Node* result_c = new Node;
        
        result_h = result_c;
        Node* temp_node = NULL;
        
        stack<Node*> s;
        temp_node = head;
        s.push(head);
        
        while(!s.empty()){
            // check temp_node->next first but it's priority is not the highest for stack property
            if(temp_node->next != NULL){         
                s.push(temp_node->next);
            }
            
            if(temp_node->child != NULL){
                s.push(temp_node->child);
            }
            
            result_c->next = temp_node;
            result_c->next->prev = result_c;
            result_c->child = NULL;
            result_c = result_c->next;
            
            temp_node = s.top();
            s.pop();
        }
        
        // deal with head node situation (revised)
        result_h = result_h->next;
        result_h->prev = NULL;
        
        return result_h;
    }
};