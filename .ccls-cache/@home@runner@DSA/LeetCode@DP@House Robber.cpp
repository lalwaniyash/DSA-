class Solution {
public:
    int f(int ind, vector<int>nums, vector<int> &dp){
        if(ind == 0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + f(ind - 2, nums, dp);
        int notPick = 0 + f(ind - 1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};