/*
    Date: 2020/5/18
    Owner: Chun-Yeh, Lin
    Note: Trie(Prefix Tree)
*/


struct Node{
    // pointers array
    struct Node** next = new Node*[26]{NULL};
    // indicate the note is end or not
    bool end=false;
};

class Trie {
public:
    struct Node root;
    /** Initialize your data structure here. */
    Trie() {
        root.end=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int length = word.length();
        int i=0;
        struct Node* temp=&root;
        while(i<length){
            if(temp->next[word[i]-'a']){ 
                temp = temp->next[word[i]-'a'];    
            }else{
                temp -> next[word[i]-'a'] = new Node;
                temp  = temp->next[word[i]-'a'];
            }
            if(i==length-1)temp->end=true;
            i++;
            
                   
        }

        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int length = word.length();
        int i=0;
        struct Node* temp=&root;
        while(temp){
            if(i==length){
                if(temp->end==true)return true;
                else return false;
            }

            if(temp->next[word[i]-'a']){
                // exist
                temp = temp->next[word[i]-'a'];
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int length = prefix.length();
        int i=0;
        struct Node* temp=&root;
        while(temp){
            if(i==length)return true;
            if(temp->next[prefix[i]-'a']){
                // exist
                temp = temp->next[prefix[i]-'a'];
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */