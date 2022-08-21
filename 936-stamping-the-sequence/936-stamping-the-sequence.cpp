class Solution {
public:
    bool canreplace(string&stamp,string&target,int pos){
        for(int i=0;i<stamp.size();i++){
            if(target[i+pos]!='?'&&target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    int replace(string&stamp,string&target,int pos){
        int count=0;
        for(int i=0;i<stamp.size();i++){
            if(target[i+pos]!='?'){
                count++;
                target[i+pos]='?';
            }
        }
        return count;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>res;
        int count=0;
        int m=stamp.size(),n=target.size();
        vector<int>v(n+1,0);
        while(count!=n){
            bool flag=false;
            for(int i=0;i<=n-m;i++){
                if(v[i]==0&&canreplace(stamp,target,i)){
                    flag=true;
                    v[i]=1;
                    count+=replace(stamp,target,i);
                    res.push_back(i);
                    if(count==n)
                        break;
                }
            }
            if(flag==false){
                vector<int>temp;
                return temp;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};