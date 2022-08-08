class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(res.begin(),res.end(),nums[i]);
            if(it!=res.end())
                *it=nums[i];
            else
                res.push_back(nums[i]);
        }
        return res.size();
    }
};