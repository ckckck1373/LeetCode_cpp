/*
    Date: 4/28/2020
    Double Linked List with unordered map again
    Use queue STL might be more efficient.
*/


class Node{
public:
    int value;
    Node* previous;
    Node* next;
};

class DoubleLinkedList{
public:
    Node *header;
    DoubleLinkedList(){
        header = new Node;
        header -> value = 0; //size
        header -> next = header;
        header -> previous = header;
        
    }
    
    void Insert(Node* in, Node* place){ 
        in -> previous = place->previous;
        in -> next = place;
        place -> previous -> next = in;
        place -> previous = in;
    }
    
    void Remove(Node* in){
        if(in==header){
            cout << "delete head condition";
            throw "Deletion of header node not permited";
        }else{
            in -> previous -> next = in -> next;
            in -> next -> previous= in -> previous ;
            delete in;
        }
    }
};

class FirstUnique {
public:
    DoubleLinkedList List;
    unordered_map<int, Node*> dict;
    unordered_map<int, Node*>::iterator iter;
    
    inline FirstUnique(vector<int>& nums) {
        Node* temp;
        for(long long i=0;i<nums.size();i++){
            iter = dict.find(nums[i]);
            if(iter==dict.end()){
                // new value
                temp =  new Node;
                dict[nums[i]]=temp;
                temp -> value = nums[i];
                temp -> previous = NULL;
                temp -> next = NULL;
                List.header->value++;
                List.Insert(temp, List.header);
            }else if(iter->second!=NULL){
                // Second time
                List.Remove(dict[nums[i]]);
                dict[nums[i]]=NULL;
                List.header->value--;
            }  
        }
    }
    
    int showFirstUnique() {
        if(List.header->value==0){
            return -1;
        }else{
             return List.header->next->value;
        }
       
    }
    
    void add(int value) {
        Node* temp;
        iter = dict.find(value);
        if(iter==dict.end()){
            // new value
            temp =  new Node;
            dict[value]=temp;
            temp -> value = value;
            temp -> previous = NULL;
            temp -> next = NULL;
            List.header->value++;
            List.Insert(temp, List.header);
        }else if(iter->second!=NULL){
            // Second time
            List.Remove(dict[value]);
            dict[value]=NULL;
            List.header->value--;
        }

    }
    
    void print(){
        for(auto& u:dict){
            cout << "u.first: " <<  u.first << endl;
            cout << " u.second->data: " <<  u.second->value << endl;

        }
            cout << endl;
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */