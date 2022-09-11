class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        long long int sum=0,res=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int cef=v[i][0];
            int csp=v[i][1];
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            pq.push(csp);
            sum+=csp;
            res=max(res,sum*cef);
        }
        return res%1000000007;
    }
};