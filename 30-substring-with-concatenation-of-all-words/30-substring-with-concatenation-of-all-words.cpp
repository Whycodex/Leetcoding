class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int target=words.size()*words[0].length();
        vector<int>res;
        if(s.length()<target)
            return res;
        for(int i=0;i<=s.length()-target;i++){
            unordered_map<string,int>m;
            for(int j=0;j<words.size();j++){
                m[words[j]]++;
            }
            int k;
            for(k=0;k<words.size();k++){
                string temp=s.substr(i+k*words[0].length(),words[0].length());
                if(m.count(temp)==0)
                    break;
                else{
                    if(m[temp]!=0)
                        m[temp]--;
                    else
                        break;
                }
            }
            if(k==words.size())
                res.push_back(i);
        }
        return res;
    }
};