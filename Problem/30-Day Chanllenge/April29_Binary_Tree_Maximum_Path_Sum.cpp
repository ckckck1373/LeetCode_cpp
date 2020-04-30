/*
    Date: 4/30
    Binary tree
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
    int result=INT_MIN;
    int maxPathSum(TreeNode* root){
    
        Postorder(root);
        
        return result;
    }
    
    
    void Postorder(TreeNode *currentNode){
        if(currentNode){
            Postorder(currentNode->left);
            Postorder(currentNode->right);
            Visit(currentNode);
        }
    }
    
    void Visit(TreeNode *currentNode){
        int left=0;
        int right=0;
        int current_result=0;
  
        // diff possible result;
        int sum_three=0;
        int sum_two=0;
        int sum_one=0;
        if(currentNode==NULL){
            return;
        }else{
            
            left = (currentNode->left==NULL)? -10000000:currentNode->left->val;
            right = (currentNode->right==NULL)? -10000000:currentNode->right->val;
            // path current max

            sum_three = left + right + currentNode->val;
 
            sum_two = max(left+currentNode->val, right+currentNode->val);
            sum_one = max(left, right);
            sum_one = max(sum_one, currentNode->val);
            current_result= max(sum_three, sum_two);
            current_result= max(current_result, sum_one);


            if(max(left, right)>0){
                currentNode->val += max(left, right);
            }
           
            //
            result = (result<current_result)? current_result:result;
        }
    }
    


};


/*
    max({a, b, c}); // can compare more items 

*/