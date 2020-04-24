/*
    Date: 4/24/2020
    Binary Search Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* node;

        int num=preorder.size();
        int value=0;
        for(int i=1;i<num;i++){
            node = root;
            value = preorder[i];
            helper(node, value);
        }
        
        return root;
    }
    
   inline void helper(TreeNode* node, int value){
        if(value < node->val){
            if(node->left!=0){
                node = node->left;
                helper(node, value);
            }else{
                node->left = new TreeNode(value);
            }
        }else{
            if(node->right!=0){
                node = node->right;
                helper(node, value);
            }else{
                node->right = new TreeNode(value);
            }
        }  
    }
};