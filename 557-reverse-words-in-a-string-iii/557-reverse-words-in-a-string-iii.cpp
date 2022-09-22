class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string temp="";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            if(s[i]==' '){
                temp.pop_back();
                reverse(temp.begin(),temp.end());
                res+=temp+' ';
                temp="";
            }
        }
        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;
    }
};