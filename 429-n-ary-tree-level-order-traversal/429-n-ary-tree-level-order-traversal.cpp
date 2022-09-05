/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<Node*>q;
        q.push(root);
        while(q.empty()==false){
            int count=q.size();
            vector<int>v;
            for(int i=0;i<count;i++){
                Node*cur=q.front();
                q.pop();
                v.push_back(cur->val);
                for(auto i:cur->children){
                    q.push(i);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};