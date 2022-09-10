class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0||prices.size()==0||prices.size()==1)
            return 0;
        vector<vector<int>>v(k+1,vector<int>(prices.size()));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(i==0)
                    v[i][j]=0;
                else if(j==0)
                    v[i][j]=0;
                else{
                    int res=INT_MIN;
                    for(int k=0;k<j;k++){
                        int temp=prices[j]-prices[k]+v[i-1][k];
                        res=max(res,temp);
                    }
                    v[i][j]=max(v[i][j-1],res);
                }
            }
        }
        return v[v.size()-1][prices.size()-1];
    }
};