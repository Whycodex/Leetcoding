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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(todo.empty()==false){
            auto p=todo.front();
            todo.pop();
            TreeNode*node=p.first;
            int x=p.second.first,y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left!=NULL)
                todo.push({node->left,{x-1,y+1}});
            if(node->right!=NULL)
                todo.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>>res;
        for(auto i:nodes){
            vector<int>v;
            for(auto j:i.second){
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            res.push_back(v);
        }
        return res;
    }
};