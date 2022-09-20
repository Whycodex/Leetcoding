class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v(nums2.size()+1);
        int res=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j])
                    v[j+1]=1+v[j];
                else
                    v[j+1]=0;
                res=max(res,v[j+1]);
            }
        }
        return res;
    }
};