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
    vector<vector<int>>res;
    vector<int>v;
    void helper(TreeNode*root,int cur,int target){
        if(root==NULL)
            return;
        cur+=root->val;
        v.push_back(root->val);
        if(cur==target&&root->left==NULL&&root->right==NULL){
            res.push_back(v);
        }
        helper(root->left,cur,target);
        helper(root->right,cur,target);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,0,targetSum);
        return res;
    }
};