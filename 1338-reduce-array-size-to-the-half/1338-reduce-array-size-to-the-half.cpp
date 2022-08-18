class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<int>v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int target=arr.size()/2;
        int sum=0,count=0;
        for(auto i:v){
            sum+=i;
            count++;
            if(sum>=target){
                return count;
                
            }
        }
        return 0;
    }
};