// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    {   
        stack<string>st;
        string ans = "";
        
        for(int i = 0; i < S.length(); i++){
            string temp = "";
            while(S[i]!='.' && i<S.length()){
                temp+=S[i];
                i++;
            }
            st.push(temp);
            st.push(".");
        }
        st.pop();
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends