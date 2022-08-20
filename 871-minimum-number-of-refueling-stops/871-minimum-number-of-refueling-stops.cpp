class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res=0;
        priority_queue<int>pq;
        int cur=startFuel;
        int i=0;
        while(cur<target){
            while(i<stations.size()&&stations[i][0]<=cur){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()==true)
                return -1;
            cur+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};