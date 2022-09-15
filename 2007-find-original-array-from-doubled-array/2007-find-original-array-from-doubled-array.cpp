class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>res;
        if(changed.size()%2!=0)
            return res;
        sort(changed.begin(),changed.end());
        unordered_map<int,int>m;
        for(int i=0;i<changed.size();i++){
            m[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++){
            if(m[changed[i]]==0)
                continue;
            if(m[changed[i]*2]==0){
                vector<int>v;
                return v;
            }
            res.push_back(changed[i]);
            m[changed[i]]--;
            m[changed[i]*2]--;
        }
        return res;
    }
};