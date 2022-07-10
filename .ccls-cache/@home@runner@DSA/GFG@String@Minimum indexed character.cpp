// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {   
        unordered_map<char, bool>mp;
        
        for(int i = 0; i < patt.size(); i++) {
            mp[patt[i]] = true;
        }
        for(int i = 0; i < str.size(); i++) {
            if(mp[str[i]] == true) return i;
        }
        return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends