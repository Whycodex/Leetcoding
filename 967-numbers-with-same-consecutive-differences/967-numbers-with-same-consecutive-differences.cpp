class Solution {
public:
    void helper(long long int num,int n,int k,vector<int>&res){
        if(n==0){
            res.push_back(num);
            return;
        }
        int low=(num==0)?1:0;
        for(int i=low;i<10;i++){
            if(num&&abs(i-num%10)!=k)
                continue;
            num*=10;
            num+=i;
            helper(num,n-1,k,res);
            num/=10;
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        long long int num=0;
        helper(num,n,k,res);
        return res;
    }
};