class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int l=0,r=arr.size()-1;
        while(l<=r){
            if((r-l)+1>k){
                if(abs(arr[l]-x)>abs(arr[r]-x))
                    l++;
                else
                    r--;
            }
            else{
                res.push_back(arr[l]);
                l++;
            }
        }
        return res;
    }
};