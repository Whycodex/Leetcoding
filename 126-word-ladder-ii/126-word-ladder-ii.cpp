class Solution {
public:
    vector<vector<string>>res;
    vector<string>tem;
    unordered_map<string,int>m;
    string str;
    void helper(string s){
        tem.push_back(s);
        if(s==str){
            vector<string>x=tem;
            reverse(x.begin(),x.end());
            res.push_back(x);
            tem.pop_back();
            return;
        }
        int cur=m[s];
        for(int i=0;i<s.size();i++){
            char c=s[i];
            for(char ch='a';ch<='z';ch++){
                s[i]=ch;
                if(m.count(s)!=0&&m[s]==cur-1)
                    helper(s);
            }
            s[i]=c;
        }
        tem.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        str=beginWord;
        queue<string>q;
        q.push({beginWord});
        m[beginWord]=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string t=q.front();
                q.pop();
                int x=m[t]+1;
                for(int i=0;i<beginWord.size();i++){
                    string temp=t;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(!m.count(temp)&&dict.count(temp)){
                            m[temp]=x;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        if(m.count(endWord))
            helper(endWord);
        return res;
    }
};