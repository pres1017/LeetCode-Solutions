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
    /*
    int biggestLeft(TreeNode* root){
        int max = root->val;
        TreeNode* temp = root->left;
        if(temp != nullptr){
            if(temp->val > max) max = temp->val;
            while(temp->right != nullptr){
                temp = temp->right;
                if(temp->val > max) max = temp->val;
            }
        }
        return max;
    }
    
    int smallestRight(TreeNode* root){
        int min = root->val;
        TreeNode* temp = root->right;
        if(temp != nullptr){
            if(temp->val < min) min = temp->val;
            while(temp->left != nullptr){
                temp = temp->left;
                if(temp->val < min) min = temp->val;
            }
        }
        return min;
    }
    */
    bool traverse(TreeNode* root, long low, long high){
        if(root == nullptr) return true;
        else if(root->val >= high) return false;
        else if(root->val <= low) return false;
        else return traverse(root->left, low, root->val) && traverse(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root){
        return traverse(root, INT64_MIN, INT64_MAX);
    }
};