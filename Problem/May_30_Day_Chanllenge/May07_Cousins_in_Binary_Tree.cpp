/*
    Date: 2020/5/7
    Owner: Chun-Yeh, Lin
    Note: Tree with two pointer(can trace back)
*/

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
class Solution {
public:
    int x_d=0;
    int y_d=0;
    bool result=true;
    //bool flag=true;
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)return false;
        
        helper(root->left, root, x, y, 0);
        helper(root->right, root, x, y, 0);

        if(result==false){
            return false;
        }else{
            if(x_d==y_d)return true;
            else return false;
        }
        
        cout << "wrong" << endl;
        return 0;
    }
    
    
     void helper(TreeNode *Node, TreeNode *Node_p, int x, int y, int depth){
        //terminate condition
        if(!Node)return;
         
        TreeNode* temp = Node;

        if(Node->val==x){
            if(((Node_p->left)&&Node_p->left->val==y)||((Node_p->right)&&Node_p->right->val==y)){
                result=false;

                return;
            }
            x_d=depth;
        }else if(Node->val==y){
            if(((Node_p->left)&&Node_p->left->val==x)||((Node_p->right)&&Node_p->right->val==x)){
                result=false;
                return;
            }
            y_d=depth;
        }
        
        
        helper(temp->left, temp, x, y, depth+1);
        helper(temp->right, temp, x, y, depth+1);
        
         
         
     }
};