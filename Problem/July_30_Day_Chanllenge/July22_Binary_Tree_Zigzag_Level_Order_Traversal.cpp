/*
    Date: 2020/7/22
    Owner: Chun-Yeh, Lin
    Note: 
*/

//**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct Node{
    TreeNode* node;
    int level;
    
    Node(TreeNode* node_i, int level_i){
        node = node_i;
        level = level_i;
    }
};

typedef struct Node Node;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root) return result;
        
        vector<int> v;
        
        int cur_level=0;
        
        stack<Node*> s0;
        stack<Node*> s1;
        
        Node root_n(root, 0);
        Node* temp_node = NULL;
        s0.push(&root_n);
        
        while(!((s0.empty())&&(s1.empty()))){
            
//             if(cur_level < q.front()->level){ 
//                 result.push_back(v);
//                 v.clear();
//                 cur_level++;
//             }  
           
            
            if(cur_level%2 == 0){

                while(!s0.empty()){
                    //cout << "s0: " << s0.top()->node->val << endl;
                    v.push_back(s0.top()->node->val);
                    
                    if(s0.top()->node->left){
                        temp_node = new Node(s0.top()->node->left, s0.top()->level+1);
                        s1.push(temp_node);
                    }
                    
                    if(s0.top()->node->right){
                        temp_node = new Node(s0.top()->node->right, s0.top()->level+1);
                        s1.push(temp_node);
                    }
                    


                    s0.pop();
                }

            }else{
                while(!s1.empty()){
                    //cout << "s1: " << s1.top()->node->val << endl;
                    v.push_back(s1.top()->node->val);
                    
                    if(s1.top()->node->right){
                         //cout << "stack right! " << endl;
                        temp_node = new Node(s1.top()->node->right, s1.top()->level+1);
                        s0.push(temp_node);
                    }

                    if(s1.top()->node->left){
                        //cout << "stack left! " << endl;
                        temp_node = new Node(s1.top()->node->left,s1.top()->level+1);
                        s0.push(temp_node);
                    }
                    

                    s1.pop();
                }
            }
            
            //cout << endl;
            result.push_back(v);
            v.clear();
            cur_level++;
        }
            
            
            //cout << "cur_level: " << cur_level << " q.front()->val: " << q.front()->level << endl;
            // cout << "val: " << q.front()->node->val ;
            // cout << " level: " << q.front()->level << endl;
        return result;
    }
};