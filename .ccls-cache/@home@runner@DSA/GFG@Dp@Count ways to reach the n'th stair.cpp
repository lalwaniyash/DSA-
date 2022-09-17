//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int f(int n, vector<int> &dp){
        int mod = 1000000007;
        if(n == 0) return 1;
        if(n<0) return 0;
        if(dp[n]!= -1) return dp[n];
        int left = f(n-1, dp);
        int right = f(n-2, dp);
        return dp[n] = (left+right) % mod;
    }
    
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int mod = 1000000007;
        vector<int>dp(n+1, -1);
        f(n, dp);
        return dp[n]%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends