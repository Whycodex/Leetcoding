class Solution {
public:
    vector<char>v;
    char helper(char ch){
        return v[ch]==ch?ch:helper(v[ch]);
    }
    bool equationsPossible(vector<string>& equations) {
        v.resize(26,0);
        for(int i=0;i<26;i++){
            v[i]=i;
        }
        for(auto i:equations){
            if(i[1]=='='){
                char x=helper(i[0]-'a');
                char y=helper(i[3]-'a');
                if(x!=y)
                    v[y]=x;
            }
        }
        for(auto i:equations){
            if(i[1]=='!'){
                char x=helper(i[0]-'a');
                char y=helper(i[3]-'a');
                if(x==y)
                    return false;
            }
        }
        return true;
    }
};