class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>m;
        for(auto i:paths){
            stringstream ss(i);
            string loc,x;
            getline(ss,loc,' ');
            while(getline(ss,x,' ')){
                string name=loc+'/'+x.substr(0,x.find('('));
                string content=x.substr(x.find('(')+1,x.find(')')-x.find('(')-1);
                m[content].push_back(name);
            }
        }
        vector<vector<string>>v;
        for(auto i:m){
            if(i.second.size()>1){
                v.push_back(i.second);
            }
        }
        return v;
    }
};