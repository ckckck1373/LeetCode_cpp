/*
    Date: 4/11/2020
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
    int max_length=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        int root_result = CheckDepth(root, count);
        // cout << "root_result: " << root_result;
        return max_length;
    }
    
    int CheckDepth(TreeNode* current_node,int count){
        int left=0;
        int right=0;
        // cout << "count:  " << count  << endl;
             
        // terminate condition    
        if(current_node->left==NULL && current_node->right==NULL){
            return count;
        }else if(current_node->left==NULL){
            // cout << "only right branch"<< endl;
            left = count;
            count++;
            right = CheckDepth(current_node->right, count);
            count--;
        }else if(current_node->right==NULL){
            // cout << "only left branch"<< endl;
            count++;
            left = CheckDepth(current_node->left, count);
            count--;
            right = count;
        }else{
            // cout << "both have branch"<< endl;
            count++;
            left = CheckDepth(current_node->left, count);
            right = CheckDepth(current_node->right, count);
            count--;
        }
        
        if(max_length<=left+right-2*count){
            max_length = left+right-2*count;
        }
        
        // cout << "left: " << left << " right: " << right << endl;
        return max(left, right);
    }
    
};


/*
    The code can be more concise;
*/
ample 4 ms submission
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
    // STUDY FROM OFFICIAL
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return d;
    }

    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lLayerHeight = depth(root->left);
        int rLayerHeight = depth(root->right);
        if (lLayerHeight + rLayerHeight > d) {
            d = lLayerHeight + rLayerHeight;
        }
        return max(lLayerHeight, rLayerHeight) + 1;
    }
};