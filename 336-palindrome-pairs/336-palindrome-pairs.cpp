class Solution {
public:
    bool ispalin(string &str,int i,int j){
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        unordered_map<string,int>m;
        int idx=-1;
        vector<int>v;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]==""){
                idx=i;
                continue;
            }
            if(ispalin(words[i],0,words[i].size()-1)==true){
                v.push_back(i);
            }
            string str=words[i];
            reverse(str.begin(),str.end());
            m[str]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                if(ispalin(words[i],j,words[i].size()-1)==true){
                    string temp1=words[i].substr(0,j);
                    if(m.find(temp1)!=m.end()&&m[temp1]!=i){
                        vector<int>v;
                        v.push_back(i);
                        v.push_back(m[temp1]);
                        res.push_back(v);
                    }
                }
                if(ispalin(words[i],0,j-1)==true){
                    string temp2=words[i].substr(j);
                    if(m.find(temp2)!=m.end()&&m[temp2]!=i){
                        vector<int>v;
                        v.push_back(m[temp2]);
                        v.push_back(i);
                        res.push_back(v);
                    }
                }
            }
        }
        if(idx!=-1){
            for(auto i:v){
                vector<int>vec1,vec2;
                vec1.push_back(i);
                vec1.push_back(idx);
                res.push_back(vec1);
                vec2.push_back(idx);
                vec2.push_back(i);
                res.push_back(vec2);
            }
        }
        return res;
    }
};