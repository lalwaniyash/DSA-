class Solution {
private:
    void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        solve(nums, output, index+1, ans);
        
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        int index;
        
        solve(nums, output, index, ans);
        return ans;
    }
};