class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m1,m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m1[nums[i]]==0)
                continue;
            if(m2[nums[i]]>0){
                m1[nums[i]]--;
                m2[nums[i]]--;
                m2[nums[i]+1]++;
            }
            else if(m1[nums[i]]>0&&m1[nums[i]+1]>0&&m1[nums[i]+2]>0){
                m1[nums[i]]--;
                m1[nums[i]+1]--;
                m1[nums[i]+2]--;
                m2[nums[i]+3]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};