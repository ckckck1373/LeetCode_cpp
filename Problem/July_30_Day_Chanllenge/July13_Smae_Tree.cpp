
/*
    Date: 2020/6/14
    Owner: Chun-Yeh, Lin
    Note: Can use itself as recursive function!
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


// Version1: Run Time: 8ms(0%)/Memory Usage: 10.4MB 
//
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        else if(p==NULL || q==NULL)return false;
        bool result;
        TreeNode *p_p;
        TreeNode *q_p;
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            p_p = q1.front();
            q_p = q2.front();
            q1.pop();
            q2.pop();
            
            if(CheckValid(p_p->left, q_p->left)==false)return false;
            if(CheckValid(p_p->right, q_p->right)==false)return false;
            
            if(!(p_p->val==q_p->val)){
                return false;
            }else{
                // two node are same
                if(p_p->left)q1.push(p_p->left);
                if(p_p->right)q1.push(p_p->right);
                if(q_p->left)q2.push(q_p->left);
                if(q_p->right)q2.push(q_p->right);
            }
        }
        return true;
    }
    
    bool CheckValid(TreeNode *p_p, TreeNode *q_p){
        if(p_p==NULL && q_p==NULL){
            return true;
        }else if(p_p!=NULL && q_p!=NULL){
            if(p_p->val!=q_p->val){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
};


// Version2: Runtion: 0ms(99%)/Memory Usage: 10.4MB
// reduce if-else statement 

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        else if(p==NULL || q==NULL)return false;
        
        bool s_en;
        TreeNode *p_p;
        TreeNode *q_p;
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            p_p = q1.front();
            q_p = q2.front();
            q1.pop();
            q2.pop();
            
            if(p_p->val!=q_p->val)return false;
            if(CheckValid(p_p->left, q_p->left, s_en)==false)return false;
            if(s_en==true){
                if(p_p->left)q1.push(p_p->left);
                if(q_p->left)q2.push(q_p->left);
            }
            if(CheckValid(p_p->right, q_p->right, s_en)==false)return false;
            if(s_en==true){
                if(p_p->right)q1.push(p_p->right);
                if(q_p->right)q2.push(q_p->right);
            }
        }
        return true;
    }
    
    bool CheckValid(TreeNode *p_p, TreeNode *q_p, bool &s_en){
        if(p_p==NULL && q_p==NULL){
            s_en = false;
            return true;
        }else if(p_p!=NULL && q_p!=NULL){
            if(p_p->val!=q_p->val){
                s_en = false;
                return false;
            }else{
                s_en = true;
                return true;
            }
        }else{
            s_en = false;
            return false;
        }
    }
};
