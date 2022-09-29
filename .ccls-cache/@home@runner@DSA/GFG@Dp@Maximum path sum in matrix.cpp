//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
        if(j<0 || j>=Matrix[0].size()) return -1e9;
        if(i == 0) return Matrix[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int up = Matrix[i][j] + f(i-1,j,Matrix,dp);
        int ld = Matrix[i][j] + f(i-1,j-1,Matrix,dp);
        int rd = Matrix[i][j] + f(i-1,j+1,Matrix,dp);
        
        return dp[i][j] =  max(up, max(ld, rd));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m, -1));
        int maxi = -1e9;
        for(int j = 0; j<m; j++){
            maxi = max(maxi, f(n-1,j,Matrix, dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends