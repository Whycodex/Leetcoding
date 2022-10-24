//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&res,vector<vector<int>>&image,int newColor,int delRow[],int delCol[],int inColor){
        res[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&image[nRow][nCol]==inColor&&res[nRow][nCol]!=newColor){
                dfs(nRow,nCol,res,image,newColor,delRow,delCol,inColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int inColor=image[sr][sc];
        vector<vector<int>>res=image;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        dfs(sr,sc,res,image,newColor,delRow,delCol,inColor);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends