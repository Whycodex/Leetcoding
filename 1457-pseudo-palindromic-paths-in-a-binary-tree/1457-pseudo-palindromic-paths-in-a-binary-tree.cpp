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
    int helper(TreeNode*root,int count){
        if(root==NULL)
            return 0;
        count^=1<<root->val;
        int res=helper(root->left,count)+helper(root->right,count);
        if(root->left==NULL&&root->right==NULL&&(count&(count-1))==0)
            res++;
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root,0);
    }
};