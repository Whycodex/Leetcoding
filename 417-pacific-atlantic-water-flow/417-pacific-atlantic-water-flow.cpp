class Solution {
public:
    void helper(vector<vector<int>>&heights,vector<vector<int>>&oce,int val,int i,int j){
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size()||oce[i][j]==1||heights[i][j]<val)
            return;
        oce[i][j]=1;
        helper(heights,oce,heights[i][j],i-1,j);
        helper(heights,oce,heights[i][j],i,j-1);
        helper(heights,oce,heights[i][j],i+1,j);
        helper(heights,oce,heights[i][j],i,j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>pac(m,vector<int>(n,0)),atl(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            helper(heights,pac,heights[i][0],i,0);
            helper(heights,atl,heights[i][n-1],i,n-1);
        }
        for(int i=0;i<n;i++){
            helper(heights,pac,heights[0][i],0,i);
            helper(heights,atl,heights[m-1][i],m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]&&atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};