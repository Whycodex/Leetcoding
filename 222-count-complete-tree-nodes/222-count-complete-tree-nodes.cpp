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
    void helper(TreeNode* root, int &res){
        if(root==NULL)
            return;
        res++;
        helper(root->left,res);
        helper(root->right,res);
    }
    int countNodes(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
};