//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int helper(vector<int>&a,int i,int j,vector<vector<int>>&dp){
            if(i>j){
                return 0;
            }
            int res=INT_MIN;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int temp1=1,temp2=1;
            for(int k=i;k<=j;k++){
                if(i-1>=0){
                    temp1=a[i-1];
                }
                if(j+1<a.size()){
                    temp2=a[j+1];
                }
                res=max(res,helper(a,i,k-1,dp)+helper(a,k+1,j,dp)+a[k]*temp1*temp2);
            }
            return dp[i][j]=res;
        }
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
            vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
            return helper(a,0,N-1,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends