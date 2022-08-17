class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char,string>m;
        m.insert({'a',".-"});
        m.insert({'b',"-..."});
        m.insert({'c',"-.-."});
        m.insert({'d',"-.."});
        m.insert({'e',"."});
        m.insert({'f',"..-."});
        m.insert({'g',"--."});
        m.insert({'h',"...."});
        m.insert({'i',".."});
        m.insert({'j',".---"});
        m.insert({'k',"-.-"});
        m.insert({'l',".-.."});
        m.insert({'m',"--"});
        m.insert({'n',"-."});
        m.insert({'o',"---"});
        m.insert({'p',".--."});
        m.insert({'q',"--.-"});
        m.insert({'r',".-."});
        m.insert({'s',"..."});
        m.insert({'t',"-"});
        m.insert({'u',"..-"});
        m.insert({'v',"...-"});
        m.insert({'w',".--"});
        m.insert({'x',"-..-"});
        m.insert({'y',"-.--"});
        m.insert({'z',"--.."});
        unordered_set<string>s;
        for(int i=0;i<words.size();i++){
            string temp="";
            for(int j=0;j<words[i].size();j++){
                temp+=m[words[i][j]];
            }
            cout<<temp<<endl;
            s.insert(temp);
        }
        return s.size();
    }
};