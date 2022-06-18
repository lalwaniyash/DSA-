// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:

int search(string p, string s) {
  map<char, int>m;
int ans=0;
for (auto &x : p){
       m[x]++;
   }

   int count=m.size();
   int k=p.size();
   int i=0, j=0;
   while(j<s.size()){
       if(m.find(s[j])!=m.end()){
           m[s[j]]--;
           if(m[s[j]]==0){
               count--;
           }
       }
       if (j-i+1 < k){
           j++;
       }
         else if (j-i+1 == k){
           //finding the ans
           if (count == 0){
               ans++;
           }
           if (m.find(s[i]) != m.end()){
               m[s[i]]++;
               if (m[s[i]] == 1){
                   count++;
               }
           }

           //slide the window
           i++;
           j++;
       }
   }
return ans;
}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends