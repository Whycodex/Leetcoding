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
    int findBottomLeftValue(TreeNode* root) {
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        res=root->val;
        while(!q.empty()){
            int count=q.size();
            bool flag=true;
            for(int i=0;i<count;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(flag==true){
                    res=cur->val;
                    flag=false;
                }
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
        }
        return res;
    }
};