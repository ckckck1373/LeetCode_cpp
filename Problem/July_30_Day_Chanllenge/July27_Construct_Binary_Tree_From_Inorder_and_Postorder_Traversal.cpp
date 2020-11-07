/*
    Date: 2020/7/28
    Owner: Chun_Yeh, Lin
    Note: 
*/

// version1:
// Runtime: 1848 ms(pretty bad performance since I create lots of vector)
// Memory Usage: 93.5 MB

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
    map<int, int> dictionary;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        struct TreeNode* root = NULL;
        if(inorder.size()==0)return root;
        
        root = new struct TreeNode(postorder.back());
        vector<int>inorder_l;
        vector<int>inorder_r;
        
        // use map to keep the postorder vector's info 
        Make_dict(postorder);
        //
        
        int pivot = root->val;
        Find_DivideInorder(pivot, inorder, inorder_l, inorder_r);
        
        root->left = Helper(inorder_l);
        root->right = Helper(inorder_r);
       
        
        return root;
    }
    
    void Make_dict(vector<int>& postorder){
        for(int i=0;i<postorder.size();i++){
            dictionary.emplace(postorder[i],i);
        }
        
    }
    
    void Find_DivideInorder(int& target, vector<int>& inorder, vector<int>& inorder_l, vector<int>& inorder_r){
        int idx=0;
        for(vector<int>::iterator it=inorder.begin();it!=inorder.end();++it){
            if(*it==target){
                inorder_r.assign(++it, inorder.end());
                break;
            }else{
                idx++;
                inorder_l.push_back(*it);
            }
        }
    }
    
    int FindPivot(vector<int>& inorder){
        int max_path=0;
        int result=0;
        for(int i=0;i<inorder.size();i++){
            if(dictionary[inorder[i]]>max_path){
                max_path = dictionary[inorder[i]];
                result = inorder[i];
            }
        }
        return result;
    }
    
    
    struct TreeNode* Helper(vector<int>& inorder){
        struct TreeNode* temp_node = NULL;
        
        if(inorder.size()==0){
            temp_node = NULL;
        }else if(inorder.size()==1){
            temp_node = new struct TreeNode(inorder[0]);
        }else{
            int pivot = 0;
            vector<int> inorder_l;
            vector<int> inorder_r;
            pivot = FindPivot(inorder);

            temp_node = new struct TreeNode(pivot);
            Find_DivideInorder(pivot, inorder, inorder_l, inorder_r);


            temp_node->left = Helper(inorder_l);
            temp_node->right = Helper(inorder_r); 
        }
        return temp_node;
    }
    
};