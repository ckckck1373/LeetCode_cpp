/*
    Date : 4/26
    Implement LRU
    Time complexity: O(1)
    Intro: Use Double Linked List and unordered map
        Double Linked List should keep both key and value -> fast delete or insert or move the node the certain place
        Map shoule keep the key and the Double Linked List's pointer -> fast find the key's place in Double Linked List
*/

    //friend class DblList;
    public:
        int data, key;
        DblListNode *left, *right;
};
class DblList{
    public:
        int size;
        DblListNode *head; // point to head node
        DblList(){
            size = 0;
            head = new DblListNode;
            head->right = head;
            head->left = head;
        }
    
        inline void Delete(DblListNode *x){
            if(x==head){
                cout << "delete head condition" ;
                throw "Deletion of header node not permited";
            }else{
                x->left->right=x->right;
                x->right->left=x->left;
                size--;
                delete x;
            }
        }
    
        inline void Insert(DblListNode *p, DblListNode *x){
            // Insert P node to the x node's right
            p->left=x;
            p->right=x->right;
            x->right->left=p;
            x->right=p;
            size++;
        }
    
        inline void Move(DblListNode *p, DblListNode *x){
            // Move P node to the x node's right
            p->left->right = p->right;
            p->right->left = p->left;
            Insert(p, x);
            size--;
        }
    
        
};


class LRUCache {
public:
    std::unordered_map<int, DblListNode*>LRU;
    std::unordered_map<int, DblListNode*>::iterator iter;

    int cap=0;    
    DblList List;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        iter = LRU.find(key);
        if(iter!= LRU.end()){
            // found!
            List.Move(iter->second , List.head);
            iter->second = List.head->right;
            return iter->second->data;
        }else{
            //not found
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        iter = LRU.find(key);
        DblListNode *temp;
        if(iter==LRU.end()){
            //not found
            if(List.size<cap){
                // just add in
                temp = new DblListNode;
                temp->data = value;
                temp->key = key;
                List.Insert(temp, List.head);
                LRU.emplace(key, temp);
            }else{
                // need delete first
                LRU.erase(List.head->left->key);
                List.Delete(List.head->left);
                temp = new DblListNode;
                temp->data = value;
                temp->key = key;
                List.Insert(temp, List.head);
                LRU.emplace(key, temp);

            }
        }else{
                //found!
                temp = new DblListNode;
                temp->data = value;
                temp->key = key;
                List.Delete(iter->second);
                List.Insert(temp, List.head);
                LRU[key] = List.head->right;
                
        }
        
        
        

    }

};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// some example

// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

// ["LRUCache","put","put","get","put","put","get"]
// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]

