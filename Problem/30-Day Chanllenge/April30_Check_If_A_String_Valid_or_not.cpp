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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root) return false;
        
        bool result = false;
        int num=0;
        int length=arr.size();
        //cout << "length: " << length<< endl;
        helper(root, arr, num, length,  result);
        
        return result;
    }
    
    void helper(TreeNode* root, vector<int>& arr, int num, int length, bool& result){
        if(root == NULL) return;
    
        if(arr[num]==root->val){

            if(num==length-1){
                if((!root->left) && (!root->right)){
                    result = true;
                }
                return;
            }

            if(num<length){
                helper(root->left, arr, num+1, length, result);
                helper(root->right, arr, num+1, length, result);
            }

        }
        

    
    }
};