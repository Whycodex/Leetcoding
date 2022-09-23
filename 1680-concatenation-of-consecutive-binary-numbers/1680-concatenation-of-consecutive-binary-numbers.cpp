class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res=0;
        long long int count=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)
                count++;
            res=((res<<count)+i)%1000000007;
        }
        return res;
    }
};