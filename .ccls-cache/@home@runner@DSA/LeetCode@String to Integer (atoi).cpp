class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        int ans=0;
        ss>>ans;
        return ans;
        
    }
};
