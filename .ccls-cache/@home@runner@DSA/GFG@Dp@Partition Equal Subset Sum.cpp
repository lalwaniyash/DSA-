//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int ind, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return(arr[0] == target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = f(ind-1, target, arr, dp);
        bool take = 0;
        if(arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);
        return dp[ind][target] =  take | notTake;
    }

    int equalPartition(int N, int arr[])
    {
        int arrSum = 0;
        for(int i=0; i<N; i++) arrSum+=arr[i];
        if(arrSum%2) return 0;
        int k = arrSum/2;
        vector<vector<int>> dp(N, vector<int>(k+1, -1));
        return f(N-1, k, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends