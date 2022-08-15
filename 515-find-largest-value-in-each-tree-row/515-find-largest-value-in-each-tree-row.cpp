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
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            int res=INT_MIN;
            for(int i=0;i<count;i++){
                TreeNode*cur=q.front();
                res=max(res,cur->val);
                q.pop();
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            v.push_back(res);
        }
        return v;
    }
};