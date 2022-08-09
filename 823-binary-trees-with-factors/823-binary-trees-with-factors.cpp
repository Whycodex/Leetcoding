class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod=1000000007;
        sort(arr.begin(),arr.end());
        vector<long long int>v(arr.size(),1);
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
            for(int j=i-1;j>=0;j--){
                if(arr[i]%arr[j]==0){
                    int temp=arr[i]/arr[j];
                    if(m.count(temp)>0)
                        v[i]+=(v[j]*v[m[temp]])%mod;
                }
            }
        }
        long long int res=0;
        res=accumulate(v.begin(),v.end(),0ll);
        return res%mod;
    }
};