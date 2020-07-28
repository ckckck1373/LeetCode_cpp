/*
    Date: 2020/7/10
    Owner: Chun-Yeh, Lin
    Note: Queue should save the data pointer only -> otherwise, it may result in heap used after free error
*/

// MY version


/**
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

struct node_info{
    TreeNode *node;
    int height;
    long long addr;
    
    node_info(TreeNode* node_in, int height_in, int addr_in){
        node = node_in;
        height = height_in;
        addr = addr_in;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<node_info*> q;
        struct node_info* cur_node = NULL;
        struct node_info* cur_node_son = NULL;
        struct node_info root_info(root, 1, 1);
        long long max_width=0;
        long long cur_width_left=1;
        long long cur_width_right=1;
        
        
        q.push(&root_info); // we should travel the tree w/ level order 
        cur_node = &root_info;
        
        while(!q.empty()){
            // put node in the queue
            cur_node = q.front();
            q.pop();
                
            if(cur_node->node->left!=NULL){
                cur_node_son = new struct node_info(cur_node->node->left, cur_node->height+1, cur_node->addr*2);
                q.push(cur_node_son);
            }

            if(cur_node->node->right!=NULL){
                cur_node_son = new struct node_info(cur_node->node->right, cur_node->height+1 ,cur_node->addr*2+1);
                
                q.push(cur_node_son);
            } 
            
            
            if(q.size()!=0){
                if(q.front()->height!=cur_node->height){
                    cur_width_right = cur_node->addr;
                    max_width = max(max_width, cur_width_right-cur_width_left);
                    cur_width_left = q.front()->addr;
                }
            }else{
                //q.size()==0 -> boundary condition 
                cur_width_right = cur_node->addr;
                max_width = max(max_width, cur_width_right-cur_width_left);
            }
        }
        
        return max_width+1;
    }
};



// NOTE: queue<pair<treeNode*, unsigned long long int>> can be save with following way
// Ex: 
    queue<pair<TreeNode*, unsigned long long int >>q;
    if(...){
        q.push({rNode.first->left, 2 * rNode.second + 1}); //  use {}!!
    }