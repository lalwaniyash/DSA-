// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
        int i, j;
        int res = -1;
        int n = str.length();
        unordered_map<char, int> mp;
        i = j = 0;
    
        while(j < n)
        {
            mp[str[j]]++;
            if(mp.size() == k)
                res = max(res, j-i+1);
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    mp[str[i]]--;
                    if(mp[str[i]] == 0)
                        mp.erase(str[i]);
                    ++i;
                    if(mp.size() == k)
                        res = max(res, j-i+1);
                }
            }
            ++j;
        }
    
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends