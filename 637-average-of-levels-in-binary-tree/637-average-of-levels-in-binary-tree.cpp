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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            int count=q.size();
            double sum=0,size=0;
            for(int i=0;i<count;i++){
                TreeNode*cur=q.front();
                sum+=cur->val;
                size++;
                q.pop();
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            v.push_back(sum/size);
        }
        return v;
    }
};