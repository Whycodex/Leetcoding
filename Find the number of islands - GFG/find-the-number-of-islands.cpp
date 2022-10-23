//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(q.empty()==false){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int deltar=-1;deltar<=1;deltar++){
                for(int deltac=-1;deltac<=1;deltac++){
                    int neighr=r+deltar;
                    int neighc=c+deltac;
                    if(neighr>=0&&neighr<n&&neighc>=0&&neighc<m&&grid[neighr][neighc]=='1'&&vis[neighr][neighc]==0){
                        vis[neighr][neighc]=1;
                        q.push({neighr,neighc});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends