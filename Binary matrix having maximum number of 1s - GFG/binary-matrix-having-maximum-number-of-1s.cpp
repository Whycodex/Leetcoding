//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        vector<int>res;
        int mn=N;
        int r=0,count=0;
        for(int i=0;i<N;i++){
            int ind=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            if(ind>=0&&ind<N){
                if(ind<mn){
                    mn=ind;
                    r=i;
                    count=N-ind;
                }
            }
        }
        res.push_back(r);
        res.push_back(count);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends