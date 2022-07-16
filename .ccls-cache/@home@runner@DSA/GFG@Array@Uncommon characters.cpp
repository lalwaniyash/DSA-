// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string a, string b)
        {
            vector<bool> hash_a(26, false), hash_b(26, false);
            string ans;
            
            for(auto x: a){
                hash_a[x-'a'] = true;
            }
            
            for(auto x: b){
                hash_b[x-'a'] = true;
            }
            
            for(int i=0; i<26; i++){
                if(hash_a[i] ^ hash_b[i]!=0)
                    ans+=(i + 'a');
            }
            return ans.empty() ? "-1" : ans;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends