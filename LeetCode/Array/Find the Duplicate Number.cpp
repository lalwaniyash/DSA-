class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int count = 0;
        int element;
        
        for(pair<int,int>p:mp){
            if(count<p.second){
                count = p.second;
                element = p.first;
            }
        }    
        return element;
    }
};